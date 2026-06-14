import tkinter as tk
from tkinter import ttk, messagebox, simpledialog
from PIL import Image, ImageTk
import mysql.connector
from datetime import datetime
import matplotlib.pyplot as plt

# Conectar a la base de datos
conexion = mysql.connector.connect(
    host="localhost",
    user="root",
    password="Yesterday1!",
    database="dulceria"
)

# Crear un cursor para ejecutar consultas
c = conexion.cursor()
tree = None
cart_tree = None
tree_sales = None
cart_items = []

def get_products(tree):
    # Limpiar la tabla
    records = tree.get_children()
    for element in records:
        tree.delete(element)

    # Obtener datos
    query = 'SELECT * FROM productos ORDER BY nombre_producto DESC'
    c.execute(query)
    db_rows = c.fetchall()

    # Llenar datos
    for row in db_rows:
        tree.insert('', 0, text=row[1], values=(row[2], row[3], row[4], row[5], row[6]))


def add_product(name, price, expiration_date, quantity, comments, supplier_id):
    if name and price and expiration_date and quantity and supplier_id:
        # Verificar si el producto ya existe en la base de datos
        query = 'SELECT * FROM productos WHERE nombre_producto = %s'
        c.execute(query, (name,))
        existing_product = c.fetchone()

        if existing_product:
            # El producto ya existe, por lo que actualizamos la cantidad
            new_quantity = existing_product[4] + int(quantity)  # Incrementar la cantidad existente
            query = 'UPDATE productos SET cantidad = %s WHERE nombre_producto = %s'
            c.execute(query, (new_quantity, name))
            conexion.commit()
            messagebox.showinfo("Producto actualizado",
                                f"Se ha incrementado la cantidad del producto {name} correctamente.")
        else:
            # El producto no existe, por lo que lo insertamos como un nuevo registro
            query = ('INSERT INTO productos (nombre_producto, precio, fecha_caducidad, cantidad, comentarios, '
                     'id_proveedor) VALUES (%s, %s, %s, %s, %s, %s)')
            parameters = (name, price, expiration_date, quantity, comments, supplier_id)
            c.execute(query, parameters)
            conexion.commit()
            messagebox.showinfo("Producto agregado", f"Producto {name} añadido con éxito")
        get_products(tree)  # Actualizar la tabla de productos
    else:
        messagebox.showerror("Campos vacíos", "Por favor complete todos los campos.")


def delete_product(tree):
    selected_item = tree.selection()
    if not selected_item:
        messagebox.showerror("Producto no seleccionado", "Por favor seleccione un producto para eliminar.")
        return
    name = tree.item(selected_item, 'text')
    query = 'DELETE FROM productos WHERE nombre_producto = %s'
    c.execute(query, (name,))
    conexion.commit()
    messagebox.showinfo("Producto eliminado", f"Producto {name} eliminado con éxito")
    get_products(tree)


def edit_product(tree):
    selected_item = tree.selection()
    if not selected_item:
        messagebox.showerror("Producto no seleccionado", "Por favor seleccione un producto para editar.")
        return

    # Obtener los valores actuales del producto seleccionado
    name = tree.item(selected_item, 'text')
    old_price = tree.item(selected_item, 'values')[0]
    old_expiration_date = tree.item(selected_item, 'values')[1]
    old_quantity = tree.item(selected_item, 'values')[2]
    old_comments = tree.item(selected_item, 'values')[3]
    old_supplier_id = tree.item(selected_item, 'values')[4]

    # Solicitar los nuevos valores al usuario mediante cuadros de diálogo
    new_price = simpledialog.askfloat("Nuevo precio", f"Ingrese el nuevo precio para {name}:",
                                      initialvalue=float(old_price))
    new_expiration_date = simpledialog.askstring("Nueva fecha de caducidad",
                                                 f"Ingrese la nueva fecha de caducidad para {name}:",
                                                 initialvalue=old_expiration_date)
    new_quantity = simpledialog.askinteger("Nueva cantidad", f"Ingrese la nueva cantidad para {name}:",
                                           initialvalue=int(old_quantity))
    new_comments = simpledialog.askstring("Nuevos comentarios", f"Ingrese los nuevos comentarios para {name}:",
                                          initialvalue=old_comments)
    new_supplier_id = simpledialog.askinteger("Nuevo ID de proveedor", f"Ingrese el nuevo ID de proveedor para {name}:",
                                              initialvalue=int(old_supplier_id))

    # Actualizar los valores en la base de datos si se proporcionan valores válidos
    if new_price is not None:
        query = ('UPDATE productos SET precio = %s, fecha_caducidad = %s, cantidad = %s, comentarios = %s, '
                 'id_proveedor = %s WHERE nombre_producto = %s')
        c.execute(query, (new_price, new_expiration_date, new_quantity, new_comments, new_supplier_id, name))
        conexion.commit()
        messagebox.showinfo("Producto actualizado", f"Producto {name} actualizado correctamente.")
        get_products(tree)


def navigate_to_storage():
    storage_window = tk.Toplevel(root)
    storage_window.title("Almacenamiento")

    global tree  # Declarar tree como global para modificarlo dentro de la función

    # Crear etiquetas y campos de entrada
    label_name = tk.Label(storage_window, text="Nombre:")
    label_name.grid(row=0, column=0, padx=5, pady=5, sticky=tk.E)
    name_entry = tk.Entry(storage_window)
    name_entry.grid(row=0, column=1, padx=5, pady=5)

    label_price = tk.Label(storage_window, text="Precio:")
    label_price.grid(row=1, column=0, padx=5, pady=5, sticky=tk.E)
    price_entry = tk.Entry(storage_window)
    price_entry.grid(row=1, column=1, padx=5, pady=5)

    label_expiration_date = tk.Label(storage_window, text="Fecha de caducidad:")
    label_expiration_date.grid(row=2, column=0, padx=5, pady=5, sticky=tk.E)
    expiration_date_entry = tk.Entry(storage_window)
    expiration_date_entry.grid(row=2, column=1, padx=5, pady=5)

    label_quantity = tk.Label(storage_window, text="Cantidad:")
    label_quantity.grid(row=3, column=0, padx=5, pady=5, sticky=tk.E)
    quantity_entry = tk.Entry(storage_window)
    quantity_entry.grid(row=3, column=1, padx=5, pady=5)

    label_comments = tk.Label(storage_window, text="Comentarios:")
    label_comments.grid(row=4, column=0, padx=5, pady=5, sticky=tk.E)
    comments_entry = tk.Entry(storage_window)
    comments_entry.grid(row=4, column=1, padx=5, pady=5)

    label_supplier_id = tk.Label(storage_window, text="ID de proveedor:")
    label_supplier_id.grid(row=5, column=0, padx=5, pady=5, sticky=tk.E)
    supplier_id_entry = tk.Entry(storage_window)
    supplier_id_entry.grid(row=5, column=1, padx=5, pady=5)

    # Botón para agregar producto
    button_add_product = tk.Button(storage_window, text="Agregar producto",
                                   command=lambda: add_product(name_entry.get(), price_entry.get(),
                                                               expiration_date_entry.get(), quantity_entry.get(),
                                                               comments_entry.get(), supplier_id_entry.get()))
    button_add_product.grid(row=6, column=0, columnspan=2, padx=5, pady=5)

    # Etiqueta para mensajes de salida
    message_label = tk.Label(storage_window, text="", fg="red")
    message_label.grid(row=7, column=0, columnspan=2, padx=5, pady=5)

    # Tabla
    tree = ttk.Treeview(storage_window, height=10, columns=("Precio", "Fecha de caducidad", "Cantidad", "Comentarios",
                                                            "ID de proveedor"))
    tree.grid(row=8, column=0, columnspan=2, padx=5, pady=5)
    tree.heading('#0', text='Nombre', anchor=tk.CENTER)
    tree.heading('#1', text='Precio', anchor=tk.CENTER)
    tree.heading('#2', text='Fecha de caducidad', anchor=tk.CENTER)
    tree.heading('#3', text='Cantidad', anchor=tk.CENTER)
    tree.heading('#4', text='Comentarios', anchor=tk.CENTER)
    tree.heading('#5', text='ID de proveedor', anchor=tk.CENTER)

    # Botones
    button_delete_product = tk.Button(storage_window, text="Eliminar producto", command=lambda: delete_product(tree))
    button_delete_product.grid(row=9, column=0, padx=5, pady=5)

    button_edit_product = tk.Button(storage_window, text="Editar producto", command=lambda: edit_product(tree))
    button_edit_product.grid(row=9, column=1, padx=5, pady=5)

    # Llenar la tabla con los productos
    get_products(tree)


def sell(tree):
    if not cart_items:
        messagebox.showerror("Carrito vacío", "No hay productos en el carrito para finalizar la compra.")
        return

        # Insertar los productos del carrito en la tabla de ventas
    for item in cart_items:
        name, price, quantity = item
        query = 'INSERT INTO ventas (nombre_producto, precio, cantidad) VALUES (%s, %s, %s)'
        c.execute(query, (name, price, quantity))
        conexion.commit()

    messagebox.showinfo("Compra finalizada", "La compra se ha finalizado con éxito.")
    cart_items.clear()
    for item in cart_tree.get_children():
        cart_tree.delete(item)


def add_to_cart(tree):
    selected_item = tree.selection()
    if not selected_item:
        messagebox.showerror("Producto no seleccionado", "Por favor seleccione un producto para agregar al carrito.")
        return

    # Obtener los valores del producto seleccionado
    name = tree.item(selected_item, 'text')
    price = float(tree.item(selected_item, 'values')[0])
    quantity = int(tree.item(selected_item, 'values')[2])

    # Solicitar la cantidad deseada al usuario
    quantity_to_add = simpledialog.askinteger("Cantidad", f"Ingrese la cantidad para agregar de {name}:",
                                              minvalue=1, maxvalue=quantity)

    if quantity_to_add is not None:
        # Agregar el producto al carrito
        cart_items.append((name, price, quantity_to_add))
        cart_tree.insert('', 'end', text=name, values=(price, quantity_to_add))
        messagebox.showinfo("Producto agregado", f"{quantity_to_add} unidades de {name} añadidas al carrito.")

        # Actualizar la cantidad del producto en el inventario
        new_quantity = quantity - quantity_to_add
        query = 'UPDATE productos SET cantidad = %s WHERE nombre_producto = %s'
        c.execute(query, (new_quantity, name))
        conexion.commit()
        get_products(tree)  # Actualizar la tabla de productos


def navigate_to_sell():
    #  ventas
    sells_products_window = tk.Toplevel(root)
    sells_products_window.title("Venta de producto")

    global tree, cart_tree

    # Tabla
    tree = ttk.Treeview(sells_products_window, height=10,
                        columns=("Precio", "Fecha de caducidad", "Cantidad", "Comentarios", "ID de proveedor"))
    tree.grid(row=8, column=0, columnspan=2, padx=5, pady=5)
    tree.heading('#0', text='Nombre', anchor=tk.CENTER)
    tree.heading('#1', text='Precio', anchor=tk.CENTER)
    tree.heading('#2', text='Fecha de caducidad', anchor=tk.CENTER)
    tree.heading('#3', text='Cantidad', anchor=tk.CENTER)
    tree.heading('#4', text='Comentarios', anchor=tk.CENTER)
    tree.heading('#5', text='ID de proveedor', anchor=tk.CENTER)

    # Implentar otro tree para que sea carrito
    cart_tree = ttk.Treeview(sells_products_window, height=10, columns=("Precio", "Cantidad"))
    cart_tree.grid(row=9, column=0, columnspan=2, padx=5, pady=5)
    cart_tree.heading('#0', text='Nombre', anchor=tk.CENTER)
    cart_tree.heading('#1', text='Precio', anchor=tk.CENTER)
    cart_tree.heading('#2', text='Cantidad', anchor=tk.CENTER)

    # Botones
    button_delete_product = tk.Button(sells_products_window, text="Finalizar compra", command=lambda: sell(tree))
    button_delete_product.grid(row=9, column=0, padx=5, pady=5)

    button_edit_product = tk.Button(sells_products_window, text="Agregar al carrito", command=lambda: add_to_cart(tree))
    button_edit_product.grid(row=9, column=1, padx=5, pady=5)

    # Llenar la tabla con los productos
    get_products(tree)


def navigate_to_suppliers():
    supplier_window = tk.Toplevel(root)
    supplier_window.title("Gestión de Proveedores")

    def add_supplier(name):
        if name:
            query = 'INSERT INTO provedores (nombre) VALUES (%s)'
            c.execute(query, (name,))
            conexion.commit()
            messagebox.showinfo("Proveedor agregado", f"Proveedor {name} añadido con éxito")
            get_suppliers()
        else:
            messagebox.showerror("Campo vacío", "Por favor ingrese el nombre del proveedor.")

    def get_suppliers():
        suppliers_listbox.delete(0, tk.END)
        query = 'SELECT * FROM provedores'
        c.execute(query)
        suppliers = c.fetchall()
        for supplier in suppliers:
            suppliers_listbox.insert(tk.END, f"{supplier[0]} - {supplier[1]}")

    def on_select_supplier(event):
        selected_item = event.widget.curselection()
        if selected_item:
            supplier_id, _ = suppliers_listbox.get(selected_item[0]).split(" - ")
            entry_supplier_name.delete(0, tk.END)
            entry_supplier_name.insert(0, _)
            selected_supplier.set(supplier_id)

    def edit_supplier(name, supplier_id):
        if name and supplier_id:
            query = 'UPDATE provedores SET nombre = %s WHERE id = %s'
            c.execute(query, (name, supplier_id))
            conexion.commit()
            messagebox.showinfo("Proveedor actualizado", f"Proveedor {name} actualizado correctamente.")
            get_suppliers()
        else:
            messagebox.showerror("Campo vacío", "Por favor ingrese el nombre del proveedor.")

    def delete_supplier(supplier_id):
        if supplier_id:
            query = 'DELETE FROM provedores WHERE id = %s'
            c.execute(query, (supplier_id,))
            conexion.commit()
            messagebox.showinfo("Proveedor eliminado", "Proveedor eliminado correctamente.")
            get_suppliers()
        else:
            messagebox.showerror("Proveedor no seleccionado", "Por favor seleccione un proveedor para eliminar.")

    # Frame para agregar/editar proveedores
    supplier_frame = tk.LabelFrame(supplier_window, text="Agregar/Editar Proveedor")
    supplier_frame.grid(row=0, column=0, padx=10, pady=10, sticky="nsew")

    # Etiqueta y campo de entrada para el nombre del proveedor
    tk.Label(supplier_frame, text="Nombre del Proveedor:").grid(row=0, column=0, padx=5, pady=5)
    entry_supplier_name = tk.Entry(supplier_frame)
    entry_supplier_name.grid(row=0, column=1, padx=5, pady=5)

    # Botones para agregar, editar y eliminar proveedores
    add_button = tk.Button(supplier_frame, text="Agregar Proveedor", command=lambda: add_supplier(entry_supplier_name.get()))
    add_button.grid(row=1, column=0, columnspan=2, padx=5, pady=5, sticky="we")

    edit_button = tk.Button(supplier_frame, text="Editar Proveedor", command=lambda: edit_supplier(entry_supplier_name.get(), selected_supplier.get()))
    edit_button.grid(row=2, column=0, columnspan=2, padx=5, pady=5, sticky="we")

    delete_button = tk.Button(supplier_frame, text="Eliminar Proveedor", command=lambda: delete_supplier(selected_supplier.get()))
    delete_button.grid(row=3, column=0, columnspan=2, padx=5, pady=5, sticky="we")

    # Lista de proveedores
    suppliers_listbox = tk.Listbox(supplier_window, width=50, height=15)
    suppliers_listbox.grid(row=1, column=0, padx=10, pady=10, sticky="nsew")
    suppliers_scroll = tk.Scrollbar(supplier_window, orient="vertical", command=suppliers_listbox.yview)
    suppliers_scroll.grid(row=1, column=1, sticky="ns")
    suppliers_listbox.configure(yscrollcommand=suppliers_scroll.set)
    selected_supplier = tk.StringVar()
    suppliers_listbox.bind("<<ListboxSelect>>", on_select_supplier)

    # Obtener y mostrar proveedores
    get_suppliers()



import matplotlib.pyplot as plt

def show_popular_products():
    # Obtener los datos de los 5 productos más populares
    query = 'SELECT nombre_producto, COUNT(*) AS ventas FROM ventas GROUP BY nombre_producto ORDER BY ventas DESC LIMIT 5'
    c.execute(query)
    db_rows = c.fetchall()

    # Extraer nombres de productos y ventas
    products = [row[0] for row in db_rows]
    sales = [row[1] for row in db_rows]

    # Crear el gráfico de barras
    plt.bar(products, sales)
    plt.xlabel('Productos')
    plt.ylabel('Ventas')
    plt.title('Top 5 productos más populares')
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()



def show_least_sold_products():

    # Obtener los datos de los 5 productos menos populares
    query = 'SELECT nombre_producto, COUNT(*) AS ventas FROM ventas GROUP BY nombre_producto ORDER BY ventas ASC LIMIT 5'
    c.execute(query)
    db_rows = c.fetchall()

    # Extraer nombres de productos y ventas
    products = [row[0] for row in db_rows]
    sales = [row[1] for row in db_rows]

    # Crear el gráfico de barras
    plt.bar(products, sales, color='red')  # Cambiar el color a rojo para distinguir los menos vendidos
    plt.xlabel('Productos')
    plt.ylabel('Ventas')
    plt.title('Top 5 productos menos vendidos')
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()


def get_products_running_low(tree):
    # Limpiar la tabla
    records = tree.get_children()
    for element in records:
        tree.delete(element)

    # Definir umbral de cantidad mínima
    threshold = 2  # Puedes ajustar este umbral según tus necesidades

    # Obtener los productos que están por acabarse
    query = 'SELECT nombre_producto, precio, fecha_caducidad, cantidad, comentarios, id_proveedor FROM productos WHERE cantidad <= %s'
    c.execute(query, (threshold,))
    db_rows = c.fetchall()

    # Llenar los datos en la tabla
    for row in db_rows:
        tree.insert('', 'end', text=row[0], values=(row[1], row[2], row[3], row[4], row[5]))

def show_products_running_low():
    products_running_low = tk.Toplevel(root)
    products_running_low.title("Productos por acabarse")

    global tree  # Declarar tree como global para modificarlo dentro de la función

    # Tabla
    tree = ttk.Treeview(products_running_low, height=10,
                        columns=("Precio", "Fecha de caducidad", "Cantidad", "Comentarios", "ID de proveedor"))
    tree.grid(row=8, column=0, columnspan=2, padx=5, pady=5)
    tree.heading('#0', text='Nombre', anchor=tk.CENTER)
    tree.heading('#1', text='Precio', anchor=tk.CENTER)
    tree.heading('#2', text='Fecha de caducidad', anchor=tk.CENTER)
    tree.heading('#3', text='Cantidad', anchor=tk.CENTER)
    tree.heading('#4', text='Comentarios', anchor=tk.CENTER)
    tree.heading('#5', text='ID de proveedor', anchor=tk.CENTER)

    get_products_running_low(tree)

def get_sales_by_month(tree_sales, month):
    # Limpiar la tabla
    records = tree_sales.get_children()
    for element in records:
        tree_sales.delete(element)

    # Obtener ventas del mes seleccionado
    query = 'SELECT id, nombre_producto, precio, fecha_venta FROM ventas WHERE MONTH(fecha_venta) = %s ORDER BY fecha_venta'
    c.execute(query, (month,))
    db_rows = c.fetchall()

    # Llenar datos
    for row in db_rows:
        tree_sales.insert('', 'end', text=row[1], values=(row[2], row[3]))

def sells():
    sells_window = tk.Toplevel(root)
    sells_window.title("Ventas por mes")

    global tree_sales

    # Combobox para seleccionar el mes
    months = [("Enero", 1), ("Febrero", 2), ("Marzo", 3), ("Abril", 4), ("Mayo", 5), ("Junio", 6),
              ("Julio", 7), ("Agosto", 8), ("Septiembre", 9), ("Octubre", 10), ("Noviembre", 11), ("Diciembre", 12)]

    month_var = tk.StringVar()
    month_combobox = ttk.Combobox(sells_window, textvariable=month_var, values=[m[0] for m in months])
    month_combobox.grid(row=0, column=0, padx=5, pady=5)
    month_combobox.current(datetime.now().month - 1)  # Seleccionar el mes actual por defecto

    def on_month_select(event):
        month_name = month_var.get()
        month_number = next(m[1] for m in months if m[0] == month_name)
        get_sales_by_month(tree_sales, month_number)

    month_combobox.bind("<<ComboboxSelected>>", on_month_select)

    # Tabla para mostrar las ventas
    tree_sales = ttk.Treeview(sells_window, height=10, columns=("Precio Total", "Fecha"))
    tree_sales.grid(row=1, column=0, columnspan=2, padx=5, pady=5)
    tree_sales.heading('#0', text='Producto', anchor=tk.CENTER)
    tree_sales.heading('#1', text='Precio Total', anchor=tk.CENTER)
    tree_sales.heading('#2', text='Fecha', anchor=tk.CENTER)

    # Obtener y mostrar las ventas del mes actual al abrir la ventana
    on_month_select(None)


def open_main_window():
    main_window = tk.Toplevel(root)
    main_window.title("Dulceria")

    label_home = tk.Label(main_window, text="Inicio")
    label_home.grid(row=0, column=0, columnspan=4, padx=5, pady=5)

    button_raw_storage = tk.Button(main_window, text="Almacén", command=navigate_to_storage)
    button_raw_storage.grid(row=1, column=0, padx=5, pady=5)

    button_bulk_storage = tk.Button(main_window, text="Ventas", command=sells)
    button_bulk_storage.grid(row=1, column=1, padx=5, pady=5)

    button_suppliers = tk.Button(main_window, text="Proveedores", command=navigate_to_suppliers)
    button_suppliers.grid(row=1, column=2, padx=5, pady=5)

    # Botones de la ventana principal
    button_popular_products = tk.Button(main_window, text="Productos más vendidos", command=show_popular_products)
    button_popular_products.grid(row=2, column=0, padx=5, pady=5)

    button_least_sold_products = tk.Button(main_window, text="Productos menos vendidos",
                                           command=show_least_sold_products)
    button_least_sold_products.grid(row=2, column=1, padx=5, pady=5)

    button_products_running_low = tk.Button(main_window, text="Productos por acabarse",
                                            command=show_products_running_low)
    button_products_running_low.grid(row=2, column=2, padx=5, pady=5)

    button_sale = tk.Button(main_window, text="Venta de producto", command=navigate_to_sell)
    button_sale.grid(row=1, column=4, padx=5, pady=5)


def login():
    username = entry_username.get()
    password = entry_password.get()

    # Aquí deberías tener algún tipo de validación de usuario y contraseña
    # Por ejemplo, comparando con datos almacenados en una base de datos o archivo

    if username == "admin" and password == "123":
        open_main_window()
        root.withdraw()  # Oculta la ventana principal
    else:
        messagebox.showerror("Login", "Usuario o contraseña incorrectos")


# Crear la ventana principal
root = tk.Tk()
root.title("Login")

# Cargar la imagen y redimensionarla
image = Image.open("user.png")
userphoto = ImageTk.PhotoImage(image)

# Crear etiqueta para la imagen
label_image = tk.Label(root, image=userphoto)
label_image.grid(row=0, column=0, columnspan=2, padx=5, pady=5)

# Crear etiquetas y campos de entrada
label_username = tk.Label(root, text="Usuario:")
label_username.grid(row=1, column=0, padx=5, pady=5, sticky=tk.E)

entry_username = tk.Entry(root)
entry_username.grid(row=1, column=1, padx=5, pady=5)

label_password = tk.Label(root, text="Contraseña:")
label_password.grid(row=2, column=0, padx=5, pady=5, sticky=tk.E)

entry_password = tk.Entry(root, show="*")
entry_password.grid(row=2, column=1, padx=5, pady=5)

# Botón de inicio de sesión
button_login = tk.Button(root, text="Login", command=login)
button_login.grid(row=3, column=0, columnspan=2, padx=5, pady=5)

root.mainloop()

