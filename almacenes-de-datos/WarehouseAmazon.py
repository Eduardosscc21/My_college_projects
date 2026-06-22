import tkinter as tk
from tkinter import ttk
import statistics
import mysql.connector

# Conectar a la base de datos

conexion = mysql.connector.connect(
    host="localhost",
    user="root",
    password="oculto por seguridad",
    database="amazondb"
)

# Crear un cursor para ejecutar consultas
c = conexion.cursor()

# Función para el proceso ETL
def etl_process():
    # Extracción de datos desde la base de datos
    c.execute("SELECT * FROM tablename")
    productos = c.fetchall()
    # Análisis descriptivo de los datos
    analisis_descriptivo(productos)

    # Carga de datos en la ventana de resultados
    mostrar_resultados(productos)

# Función para realizar análisis descriptivo
def analisis_descriptivo(data):
    # Encabezados de las columnas
    headers = [description[0] for description in c.description]

    # Realizar análisis descriptivo para columnas numéricas
    for idx, header in enumerate(headers):
        if isinstance(data[0][idx], (int, float)):
            columna = [fila[idx] for fila in data]
            media = statistics.mean(columna)
            mediana = statistics.median(columna)
            desviacion_estandar = statistics.stdev(columna)
            print(f"Análisis descriptivo para {header}:")
            print(f"  Media: {media}")
            print(f"  Mediana: {mediana}")
            print(f"  Desviación estándar: {desviacion_estandar}")
            print()

# Función para mostrar los resultados
def mostrar_resultados(productos):
    # Ventana para mostrar los resultados
    ventana_resultados = tk.Toplevel(root)
    ventana_resultados.title("Resultados")

    # Árbol para mostrar los datos
    arbol = ttk.Treeview(ventana_resultados)
    arbol["columns"] = tuple(productos[0])
    arbol["show"] = "headings"
    for columna in arbol["columns"]:
        arbol.heading(columna, text=columna)
    for producto in productos:
        arbol.insert("", "end", values=producto)
    arbol.pack()

# Ventana Tkinter
root = tk.Tk()
root.title("Amazon Data Warehouse")

# Botón para iniciar el proceso ETL
boton_etl = tk.Button(root, text="Ejecutar ETL", command=etl_process)
boton_etl.pack()

# Cerrar la conexión a la base de datos cuando se cierre la ventana principal
root.protocol("WM_DELETE_WINDOW", c.close)

root.mainloop()

