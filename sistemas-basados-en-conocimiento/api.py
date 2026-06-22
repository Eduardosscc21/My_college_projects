from flask import Flask, request, jsonify
import mysql.connector

app = Flask(__name__)

# Configuración de la conexión a la base de datos MySQL
db_config = {
    "host": "localhost",        # Cambia esto si tu base de datos no está en localhost
    "user": "root",             # Usuario de MySQL
    "password": "oculta por seguridad",     # Contraseña del usuario
    "database": "dulceria"      # Nombre de la base de datos
}

# Función para conectarse a la base de datos MySQL
def get_db_connection():
    return mysql.connector.connect(**db_config)

# Ruta para obtener los productos más vendidos
@app.route('/productos/populares', methods=['GET'])
def get_popular_products():
    try:
        conn = get_db_connection()
        cursor = conn.cursor(dictionary=True)
        query = '''
            SELECT nombre_producto, COUNT(*) AS ventas 
            FROM ventas 
            GROUP BY nombre_producto 
            ORDER BY ventas DESC 
            LIMIT 5
        '''
        cursor.execute(query)
        result = cursor.fetchall()
        conn.close()
        return jsonify(result)
    except mysql.connector.Error as err:
        return jsonify({"error": str(err)}), 500

# Ruta para obtener los productos menos vendidos
@app.route('/productos/menos_vendidos', methods=['GET'])
def get_least_sold_products():
    try:
        conn = get_db_connection()
        cursor = conn.cursor(dictionary=True)
        query = '''
            SELECT nombre_producto, COUNT(*) AS ventas 
            FROM ventas 
            GROUP BY nombre_producto 
            ORDER BY ventas ASC 
            LIMIT 5
        '''
        cursor.execute(query)
        result = cursor.fetchall()
        conn.close()
        return jsonify(result)
    except mysql.connector.Error as err:
        return jsonify({"error": str(err)}), 500

# Ruta para obtener productos que están por acabarse
@app.route('/productos/por_acabarse', methods=['GET'])
def get_products_running_low():
    threshold = 2
    try:
        conn = get_db_connection()
        cursor = conn.cursor(dictionary=True)
        query = '''
            SELECT nombre_producto, precio, fecha_caducidad, cantidad, comentarios, id_proveedor 
            FROM productos 
            WHERE cantidad <= %s
        '''
        cursor.execute(query, (threshold,))
        result = cursor.fetchall()
        conn.close()
        return jsonify(result)
    except mysql.connector.Error as err:
        return jsonify({"error": str(err)}), 500

# Ruta para obtener las ventas por mes
@app.route('/ventas/mes', methods=['GET'])
def get_sales_by_month():
    month = request.args.get('month')
    try:
        conn = get_db_connection()
        cursor = conn.cursor(dictionary=True)
        query = '''
            SELECT nombre_producto, precio, fecha_venta 
            FROM ventas 
            WHERE MONTH(fecha_venta) = %s 
            ORDER BY fecha_venta
        '''
        cursor.execute(query, (month,))
        result = cursor.fetchall()
        conn.close()
        return jsonify(result)
    except mysql.connector.Error as err:
        return jsonify({"error": str(err)}), 500

# Iniciar la aplicación Flask
if __name__ == '__main__':
    app.run(debug=True)
