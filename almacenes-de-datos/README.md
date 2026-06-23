# 🏢 Amazon Data Warehouse - Proceso ETL

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![Python](https://img.shields.io/badge/python-3.x-green)
![MySQL](https://img.shields.io/badge/mysql-8.0-orange)
![ETL](https://img.shields.io/badge/ETL-Process-purple)
![DataWarehouse](https://img.shields.io/badge/Data-Warehouse-red)
![Status](https://img.shields.io/badge/status-completed-brightgreen)

> Sistema de Extracción, Transformación y Carga (ETL) para un Data Warehouse de Amazon, desarrollado en Python con interfaz gráfica Tkinter y MySQL como motor de base de datos.

---

## 📋 Tabla de Contenidos
- [Descripción](#-descripción)
- [Características](#-características)
- [Tecnologías utilizadas](#-tecnologías-utilizadas)
- [Requisitos previos](#-requisitos-previos)

---

## 📖 Descripción

Este proyecto fue desarrollado para la materia de Almacenes de datos (data warehousing). El sistema implementa un proceso ETL (Extract, Transform, Load) para procesar datos de una base de datos de Amazon, realizando análisis descriptivos y visualizando los resultados de manera interactiva.

### 🎯 Objetivos del Sistema

- Extracción de datos desde una base de datos MySQL
- Análisis descriptivo de datos numéricos (media, mediana, desviación estándar)
- Visualización de datos en una interfaz gráfica
- Procesamiento ETL completo en un solo clic

### 🎓 Contexto Académico

- **Materia**: Almacenes de Datos (Data Warehousing)
- **Temas aplicados**: 
  - Procesos ETL (Extract, Transform, Load)
  - Análisis descriptivo de datos
  - Estadística básica aplicada a datos empresariales
  - Conexión Python - MySQL
  - Interfaz gráfica para visualización de datos
  - Principios de Data Warehouse

---

## ✨ Características

| Módulo | Funcionalidad | Descripción |
|--------|---------------|-------------|
| 🔄 **ETL** | Proceso completo | Extracción, Transformación y Carga de datos |
| 📊 **Análisis Descriptivo** | Estadísticas | Cálculo de media, mediana y desviación estándar |
| 📋 **Visualización** | Tabla interactiva | Muestra todos los datos en formato treeview |
| 🖥️ **Interfaz Gráfica** | Tkinter | Botón único para ejecutar todo el proceso |
| 🔌 **Conector MySQL** | Base de datos | Conexión directa a la base de datos origen |

---

## 🛠️ Tecnologías Utilizadas

| Tecnología | Versión | Propósito |
|------------|---------|-----------|
| **Python** | 3.x | Lenguaje de programación principal |
| **Tkinter** | - | Interfaz gráfica de usuario (GUI) nativa |
| **MySQL** | 8.0 | Motor de base de datos para el Data Warehouse |
| **mysql-connector-python** | 8.0 | Conector para comunicación Python-MySQL |
| **Statistics** | - | Módulo nativo de Python para análisis estadístico |

---

## ⚙️ Requisitos Previos

Antes de ejecutar el proyecto, asegúrate de tener instalado:

### Software Necesario
1. **Python 3.x** - [Descargar aquí](https://www.python.org/downloads/)
2. **MySQL Server** - [Descargar aquí](https://dev.mysql.com/downloads/mysql/)
3. **MySQL Workbench** (opcional) - Para administración visual de la BD

### Dependencias de Python

```bash
# Instalación de dependencias
pip install mysql-connector-python==8.0.33
