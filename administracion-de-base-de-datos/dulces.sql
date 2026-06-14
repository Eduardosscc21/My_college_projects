CREATE DATABASE dulceria;

USE dulceria;

CREATE TABLE provedores(
    id INT auto_increment PRIMARY KEY,
    nombre VARCHAR(30)
);

CREATE TABLE productos(
    id INT auto_increment PRIMARY KEY,
    nombre_producto VARCHAR(30),
    precio FLOAT,
    fecha_caducidad DATE,
    cantidad INT,
    comentarios VARCHAR(50),
    id_proveedor INT,
    FOREIGN KEY (id_proveedor) REFERENCES provedores(id)
);

CREATE TABLE ventas (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre_producto VARCHAR(255) NOT NULL,
    precio DECIMAL(10, 2) NOT NULL,
    cantidad INT NOT NULL,
    fecha_venta TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
