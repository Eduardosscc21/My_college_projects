import tkinter as tk
from tkinter import ttk, messagebox
import requests
import matplotlib.pyplot as plt
from PIL import Image, ImageTk
from datetime import datetime

# Función para obtener productos más vendidos desde la API
def show_popular_products():
    response = requests.get("http://127.0.0.1:5000/productos/populares")
    if response.status_code == 200:
        db_rows = response.json()
        products = [row['nombre_producto'] for row in db_rows]
        sales = [row['ventas'] for row in db_rows]

        plt.bar(products, sales)
        plt.xlabel('Productos')
        plt.ylabel('Ventas')
        plt.title('Top 5 productos más populares')
        plt.xticks(rotation=45)
        plt.tight_layout()
        plt.show()
    else:
        messagebox.showerror("Error", "No se pudieron obtener los productos más vendidos")

# Función para obtener productos menos vendidos desde la API
def show_least_sold_products():
    response = requests.get("http://127.0.0.1:5000/productos/menos_vendidos")
    if response.status_code == 200:
        db_rows = response.json()
        products = [row['nombre_producto'] for row in db_rows]
        sales = [row['ventas'] for row in db_rows]

        plt.bar(products, sales, color='red')
        plt.xlabel('Productos')
        plt.ylabel('Ventas')
        plt.title('Top 5 productos menos vendidos')
        plt.xticks(rotation=45)
        plt.tight_layout()
        plt.show()
    else:
        messagebox.showerror("Error", "No se pudieron obtener los productos menos vendidos")

# Función para obtener productos por acabarse desde la API
def show_products_running_low():
    response = requests.get("http://127.0.0.1:5000/productos/por_acabarse")
    if response.status_code == 200:
        db_rows = response.json()
        for row in db_rows:
            tree.insert('', 'end', text=row['nombre_producto'], values=(row['precio'], row['fecha_caducidad'], row['cantidad'], row['comentarios'], row['id_proveedor']))
    else:
        messagebox.showerror("Error", "No se pudieron obtener los productos por acabarse")

# Función para obtener ventas por mes desde la API
def get_sales_by_month(tree_sales, month):
    response = requests.get(f"http://127.0.0.1:5000/ventas/mes?month={month}")
    if response.status_code == 200:
        db_rows = response.json()
        for row in db_rows:
            tree_sales.insert('', 'end', text=row['nombre_producto'], values=(row['precio'], row['fecha_venta']))
    else:
        messagebox.showerror("Error", "No se pudieron obtener las ventas del mes")

# Crear la ventana principal de Tkinter
root = tk.Tk()
root.title("Sistema de Ventas y Productos")
root.geometry("800x600")

# Crear el Treeview para mostrar productos por acabarse
tree = ttk.Treeview(root, columns=('Precio', 'Fecha de Caducidad', 'Cantidad', 'Comentarios', 'Proveedor'))
tree.heading('#1', text='Precio')
tree.heading('#2', text='Fecha de Caducidad')
tree.heading('#3', text='Cantidad')
tree.heading('#4', text='Comentarios')
tree.heading('#5', text='Proveedor')
tree.pack(pady=20)

# Crear el Treeview para mostrar ventas por mes
tree_sales = ttk.Treeview(root, columns=('Precio', 'Fecha de Venta'))
tree_sales.heading('#1', text='Precio')
tree_sales.heading('#2', text='Fecha de Venta')
tree_sales.pack(pady=20)

# Botones para interactuar con la aplicación
btn_popular = tk.Button(root, text="Mostrar Productos Populares", command=show_popular_products)
btn_popular.pack(pady=10)

btn_least_sold = tk.Button(root, text="Mostrar Productos Menos Vendidos", command=show_least_sold_products)
btn_least_sold.pack(pady=10)

btn_running_low = tk.Button(root, text="Mostrar Productos por Acabarse", command=show_products_running_low)
btn_running_low.pack(pady=10)

btn_sales_by_month = tk.Button(root, text="Mostrar Ventas por Mes", command=lambda: get_sales_by_month(tree_sales, '11'))  # Mes de noviembre como ejemplo
btn_sales_by_month.pack(pady=10)

root.mainloop()
