import tkinter as tk
from tkinter import scrolledtext, messagebox
from bs4 import BeautifulSoup
import requests
import threading
import validators
import schedule
import time
import csv
from datetime import datetime
import re

class WebCrawlerApp:
    def __init__(self, master):
        self.master = master
        master.title("Web Crawler App")
        master.geometry("600x400")

        self.input_frame = tk.Frame(master)
        self.input_frame.pack(pady=10)

        self.label_url = tk.Label(self.input_frame, text="Ingrese la URL:")
        self.label_url.grid(row=0, column=0, padx=5, pady=5, sticky="w")

        self.entry_url = tk.Entry(self.input_frame, width=40)
        self.entry_url.grid(row=0, column=1, padx=5, pady=5)

        self.label_keyword = tk.Label(self.input_frame, text="Ingrese la palabra clave:")
        self.label_keyword.grid(row=1, column=0, padx=5, pady=5, sticky="w")

        self.entry_keyword = tk.Entry(self.input_frame, width=40)
        self.entry_keyword.grid(row=1, column=1, padx=5, pady=5)

        self.button_search = tk.Button(self.input_frame, text="Buscar", command=self.start_search)
        self.button_search.grid(row=2, column=0, padx=5, pady=5)

        self.button_clear = tk.Button(self.input_frame, text="Limpiar", command=self.clear_search)
        self.button_clear.grid(row=2, column=1, padx=5, pady=5)

        self.button_quit = tk.Button(self.input_frame, text="Cerrar", command=self.master.quit)
        self.button_quit.grid(row=2, column=2, padx=5, pady=5)

        self.result_frame = tk.Frame(master)
        self.result_frame.pack(padx=10, pady=10, fill=tk.BOTH, expand=True)

        self.result_text = scrolledtext.ScrolledText(self.result_frame, wrap=tk.WORD, width=60, height=15)
        self.result_text.pack(fill=tk.BOTH, expand=True)

        self.schedule_frame = tk.Frame(master)
        self.schedule_frame.pack(pady=10)

        self.label_interval = tk.Label(self.schedule_frame, text="Intervalo de búsqueda (minutos):")
        self.label_interval.grid(row=0, column=0, padx=5, pady=5, sticky="w")

        self.entry_interval = tk.Entry(self.schedule_frame, width=10)
        self.entry_interval.grid(row=0, column=1, padx=5, pady=5)

        self.button_start_schedule = tk.Button(self.schedule_frame, text="Iniciar Seguimiento", command=self.start_scheduled_search)
        self.button_start_schedule.grid(row=1, column=0, padx=5, pady=5)

        self.button_stop_schedule = tk.Button(self.schedule_frame, text="Detener Seguimiento", command=self.stop_scheduled_search)
        self.button_stop_schedule.grid(row=1, column=1, padx=5, pady=5)

        self.scheduled_event = None
        self.scheduled_thread = None
        self.stop_thread = False

    def start_search(self):
        url = self.entry_url.get()
        keyword = self.entry_keyword.get()
        
        if not validators.url(url):
            messagebox.showerror("Error", "La URL ingresada no es válida.")
            return
        
        if not keyword:
            messagebox.showerror("Error", "Debe ingresar una palabra clave.")
            return
        
        self.result_text.delete(1.0, tk.END)
        self.result_text.insert(tk.END, "Iniciando búsqueda...\n")

        search_thread = threading.Thread(target=self.perform_search, args=(url, keyword))
        search_thread.start()

    def perform_search(self, url, keyword):
        try:
            response = requests.get(url)
            response.raise_for_status()
            soup = BeautifulSoup(response.text, "html.parser")

            self.result_text.tag_configure("highlight", foreground="red", background="yellow")

            keyword_lower = keyword.lower()
            count = 0

            def highlight_and_count(text):
                nonlocal count
                words = text.split()
                for i, word in enumerate(words):
                    if keyword_lower in word.lower():
                        start_idx = max(0, i - 20)
                        end_idx = min(len(words), i + 21)
                        context = " ".join(words[start_idx:end_idx])
                        start = context.lower().find(keyword_lower)
                        end = start + len(keyword)
                        self.result_text.insert(tk.END, context[:start])
                        self.result_text.insert(tk.END, context[start:end], "highlight")
                        self.result_text.insert(tk.END, context[end:] + "\n")
                        self.result_text.insert(tk.END, "-" * 60 + "\n")
                        count += 1

            headings = soup.find_all(re.compile(r'^h\d$'))
            for heading in headings:
                text = heading.get_text(strip=True)
                highlight_and_count(text)

            paragraphs = soup.find_all("p")
            for paragraph in paragraphs:
                text = paragraph.get_text(strip=True)
                highlight_and_count(text)

            if count == 0:
                self.result_text.insert(tk.END, "No se encontraron resultados para la palabra clave.\n")
            else:
                self.result_text.insert(tk.END, f"Búsqueda completa. La palabra clave '{keyword}' apareció {count} veces.\n")

            self.save_results(url, keyword, count)
        except requests.RequestException as e:
            messagebox.showerror("Error", f"Error al procesar {url}: {str(e)}")

    def clear_search(self):
        self.entry_url.delete(0, tk.END)
        self.entry_keyword.delete(0, tk.END)
        self.result_text.delete(1.0, tk.END)

    def save_results(self, url, keyword, count):
        with open('datos.csv', mode='a', newline='', encoding='utf-8') as file:
            writer = csv.writer(file)
            writer.writerow([datetime.now(), url, keyword, count])

    def start_scheduled_search(self):
        interval = self.entry_interval.get()
        if not interval.isdigit() or int(interval) <= 0:
            messagebox.showerror("Error", "El intervalo debe ser un número positivo.")
            return

        url = self.entry_url.get()
        keyword = self.entry_keyword.get()
        
        if not validators.url(url):
            messagebox.showerror("Error", "La URL ingresada no es válida.")
            return
        
        if not keyword:
            messagebox.showerror("Error", "Debe ingresar una palabra clave.")
            return
        
        interval = int(interval)
        self.scheduled_event = schedule.every(interval).minutes.do(self.start_search)
        
        self.stop_thread = False
        self.scheduled_thread = threading.Thread(target=self.run_scheduled_search)
        self.scheduled_thread.start()

    def stop_scheduled_search(self):
        if self.scheduled_event:
            schedule.cancel_job(self.scheduled_event)
            self.scheduled_event = None
        
        self.stop_thread = True
        if self.scheduled_thread:
            self.scheduled_thread.join()
            self.scheduled_thread = None

    def run_scheduled_search(self):
        while not self.stop_thread:
            schedule.run_pending()
            time.sleep(1)

def main():
    root = tk.Tk()
    app = WebCrawlerApp(root)
    root.mainloop()

if __name__ == "__main__":
    main()
