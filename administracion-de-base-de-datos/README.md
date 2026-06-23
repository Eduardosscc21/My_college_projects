# 🍬 Sistema de gestión de dulcería

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![Python](https://img.shields.io/badge/python-3.x-green)
![MySQL](https://img.shields.io/badge/mysql-8.0-orange)
![Tkinter](https://img.shields.io/badge/tkinter-GUI-purple)
![License](https://img.shields.io/badge/license-MIT-yellow)
![Status](https://img.shields.io/badge/status-completed-brightgreen)

> Sistema de escritorio para la administración de inventario, ventas y proveedores de una dulcería, desarrollado en Python con interfaz gráfica Tkinter y MySQL como motor de base de datos.

---

## 📋 Tabla de contenidos
- [Descripción](#-descripción)
- [Características](#-características)
- [Tecnologías utilizadas](#-tecnologías-utilizadas)
- [Requisitos previos](#-requisitos-previos)


---

## 📖 Descripción

Este proyecto fue desarrollado como trabajo final para la materia de administración de bases de datos. El sistema permite gestionar de manera integral una dulcería, ofreciendo funcionalidades para:

### 🎯 Objetivos del sistema
- Control de inventario de productos con registro de cantidades y fechas de caducidad
- Gestión de proveedores para mantener un catálogo actualizado
- Registro de ventas con actualización automática del stock
- Análisis de datos mediante gráficos de productos más y menos vendidos
- Alertas inteligentes de productos por agotarse (stock ≤ 2 unidades)
- Interfaz intuitiva con menús modulares para cada funcionalidad

### 🎓 Contexto académico
- Materia: Administración de bases de datos
- Temas aplicados: 
  - Diseño de bases de datos relacionales
  - Consultas SQL (SELECT, INSERT, UPDATE, DELETE)
  - Llaves primarias y foráneas
  - Integridad referencial
  - Conexión Python - MySQL
  - Interfaz gráfica para gestión de datos

---

## ✨ Características

| Módulo | Funcionalidad | Descripción |
|--------|---------------|-------------|
| 🔐 Login | Autenticación | Sistema de acceso con usuario y contraseña |
| 📦 Almacén | CRUD Completo | Agregar, editar, eliminar y consultar productos |
| 🛒 Ventas | Carrito de Compras | Sistema de carrito con múltiples productos |
| 📊 Reportes | Estadísticas | Gráficos de productos más/menos vendidos |
| ⚠️ Alertas | Stock Bajo | Identificación de productos con inventario crítico |
| 🏢 Proveedores | Gestión | CRUD completo de proveedores |
| 📈 Ventas por Mes | Filtrado | Visualización de ventas por mes específico |
| 🔄 Actualización Automática | Inventario | Actualización de stock al realizar ventas |

---

## 🛠️ Tecnologías utilizadas

| Tecnología | Versión | Propósito |
|------------|---------|-----------|
| **Python** | 3.x | Lenguaje de programación principal |
| **Tkinter** | - | Interfaz gráfica de usuario (GUI) nativa |
| **MySQL** | 8.0 | Motor de base de datos relacional |
| **mysql-connector-python** | 8.0 | Conector para comunicación Python-MySQL |
| **Pillow (PIL)** | 9.x | Manejo y redimensionamiento de imágenes |
| **Matplotlib** | 3.x | Generación de gráficos estadísticos |
| **MySQL Workbench** | 8.0 | Diseño y administración visual de la BD |

---

## ⚙️ Requisitos previos

Antes de ejecutar el proyecto, asegúrate de tener instalado:

### Software necesario
1. **Python 3.x** - [Descargar aquí](https://www.python.org/downloads/)
2. **MySQL Server** - [Descargar aquí](https://dev.mysql.com/downloads/mysql/)
3. **MySQL Workbench** (opcional) - Para administración visual de la BD

### Dependencias de Python

```bash
# Instalación de dependencias
pip install mysql-connector-python==8.0.33
pip install Pillow==9.5.0
pip install matplotlib==3.7.1

