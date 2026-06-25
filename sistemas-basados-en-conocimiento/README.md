# 🧠 Sistema de Ventas y Productos - API REST - Sistemas Basados en Conocimiento

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![Python](https://img.shields.io/badge/python-3.x-green)
![Flask](https://img.shields.io/badge/Flask-2.0-red)
![MySQL](https://img.shields.io/badge/mysql-8.0-orange)
![Tkinter](https://img.shields.io/badge/tkinter-GUI-purple)
![REST](https://img.shields.io/badge/REST-API-brightgreen)
![Status](https://img.shields.io/badge/status-completed-brightgreen)

> Sistema cliente-servidor con arquitectura REST API para la gestión de productos, ventas y reportes de una dulcería, desarrollado con Flask, MySQL y Tkinter.

---

## 📋 Tabla de Contenidos
- [Descripción](#-descripción)
- [Características](#-características)
- [Tecnologías Utilizadas](#-tecnologías-utilizadas)
- [Requisitos Previos](#-requisitos-previos)

---

## 📖 Descripción

Este proyecto fue desarrollado para la materia de sistemas basados en conocimiento. El sistema implementa una arquitectura cliente-servidor donde:

- **Servidor**: API REST construida con **Flask** que expone endpoints para consultar productos y ventas
- **Cliente**: Aplicación de escritorio con **Tkinter** que consume la API y visualiza datos
- **Base de datos**: **MySQL** para almacenamiento persistente de información

### 🎯 Objetivos del sistema

- Arquitectura cliente-servidor: Separación clara entre frontend y backend
- API RESTful: Endpoints para consultar productos y ventas
- Visualización de datos: Gráficos y tablas interactivas
- Reportes dinámicos: Productos populares, menos vendidos y por acabarse
- Comunicación HTTP: Consumo de API con `requests`
- Persistencia de datos: MySQL como sistema de base de datos

### 🎓 Contexto académico

- **Materia**: Sistemas Basados en Conocimiento
- **Temas aplicados**:
  - Arquitectura cliente-servidor
  - API RESTful
  - Protocolo HTTP
  - Bases de datos relacionales
  - Interfaces gráficas de usuario
  - Visualización de datos
  - Sistemas de información

---

## ✨ Características

| Módulo | Funcionalidad | Descripción |
|--------|---------------|-------------|
| 🖥️ **Servidor Flask** | API REST | Endpoints para consultar datos |
| 📱 **Cliente Tkinter** | Interfaz gráfica | Consumo de API y visualización |
| 📊 **Productos Populares** | Reporte | Top 5 productos más vendidos |
| 📉 **Productos Menos Vendidos** | Reporte | Top 5 productos menos vendidos |
| ⚠️ **Productos por Acabarse** | Alerta | Productos con stock ≤ 2 unidades |
| 📅 **Ventas por Mes** | Reporte | Ventas filtradas por mes |
| 📈 **Gráficos** | Visualización | Matplotlib para gráficos de barras |
| 🗄️ **Base de Datos** | MySQL | Almacenamiento persistente |

---

## 🛠️ Tecnologías Utilizadas

| Tecnología | Versión | Propósito |
|------------|---------|-----------|
| **Python** | 3.x | Lenguaje de programación principal |
| **Flask** | 2.0 | Framework para API REST |
| **MySQL** | 8.0 | Base de datos relacional |
| **mysql-connector-python** | 8.0 | Conector MySQL para Python |
| **Tkinter** | - | Interfaz gráfica de usuario |
| **requests** | 2.x | Consumo de API HTTP |
| **Matplotlib** | 3.x | Generación de gráficos |
| **Pillow (PIL)** | 9.x | Manejo de imágenes |
| **JSON** | - | Formato de intercambio de datos |

---

## ⚙️ Requisitos previos

### Software necesario
1. **Python 3.x** - [Descargar aquí](https://www.python.org/downloads/)
2. **MySQL server** - [Descargar aquí](https://dev.mysql.com/downloads/mysql/)
3. **MySQL workbench** (opcional) - Administración visual de la BD

### Dependencias de python

```bash
# Instalación de dependencias
pip install Flask==2.0.1
pip install mysql-connector-python==8.0.33
pip install requests==2.26.0
pip install matplotlib==3.5.1
pip install Pillow==9.0.0
