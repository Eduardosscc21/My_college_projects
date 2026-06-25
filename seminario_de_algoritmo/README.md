# Sistema de visualización de partículas 

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![Python](https://img.shields.io/badge/python-3.x-green)
![PySide2](https://img.shields.io/badge/PySide2-5.15-orange)
![Qt](https://img.shields.io/badge/Qt-5.15-purple)
![JSON](https://img.shields.io/badge/JSON-Files-yellow)
![Algorithms](https://img.shields.io/badge/Algorithms-Fuerza_Bruta-red)
![Status](https://img.shields.io/badge/status-completed-brightgreen)

> Sistema interactivo para la gestión y visualización de partículas con interfaz gráfica Qt, implementando algoritmos de fuerza bruta para encontrar los puntos más cercanos.

---

## 📋 Tabla de Contenidos
- [Descripción](#-descripción)
- [Características](#-características)
- [Tecnologías Utilizadas](#-tecnologías-utilizadas)
- [Requisitos Previos](#-requisitos-previos)

---

## 📖 Descripción

Este proyecto fue desarrollado para la materia de Seminario de algoritmos. El sistema permite la gestión interactiva de partículas mediante una interfaz gráfica construida con PySide2 (Qt)**. Implementa operaciones CRUD, ordenamiento, persistencia en JSON, y algoritmos de fuerza bruta para encontrar los puntos más cercanos entre partículas.

### 🎯 Objetivos del Sistema

- Gestión de partículas: Crear, eliminar, modificar y visualizar partículas
- Interfaz gráfica interactiva: Qt con múltiples pestañas para diferentes funcionalidades
- Algoritmos de fuerza bruta: Encontrar el punto más cercano para cada partícula
- Visualización gráfica: Dibujar partículas y conexiones en un lienzo
- Persistencia de datos: Guardar y cargar en formato JSON
- Múltiples ordenamientos: Por ID, distancia y velocidad
- Zoom interactivo: Zoom con rueda del mouse

### 🎓 Contexto académico

- **Materia**: Seminario de algoritmos
- **Temas aplicados**: 
  - Algoritmos de fuerza bruta
  - Estructuras de datos (listas enlazadas)
  - Algoritmos de ordenamiento
  - Distancia euclidiana
  - Programación orientada a objetos
  - Interfaces gráficas con Qt
  - Persistencia de datos (JSON)

---

## ✨ Características

| Módulo | Funcionalidad | Descripción |
|--------|---------------|-------------|
| 🎨 **Agregar** | CRUD de partículas | Agregar al inicio/final, mostrar |
| 📊 **Tabla** | Visualización tabular | Tabla con todas las partículas |
| 🖼️ **Dibujo** | Visualización gráfica | Lienzo con partículas y conexiones |
| 🔍 **Búsqueda** | Búsqueda por ID | Encontrar partícula específica |
| 📁 **Archivos** | JSON | Guardar y abrir archivos JSON |
| 🔄 **Ordenamiento** | Múltiples criterios | ID, distancia, velocidad |
| 🧮 **Algoritmos** | Fuerza bruta | Puntos más cercanos |
| 🖱️ **Zoom** | Interacción | Zoom con scroll del mouse |

---

## 🛠️ Tecnologías Utilizadas

| Tecnología | Versión | Propósito |
|------------|---------|-----------|
| **Python** | 3.x | Lenguaje de programación principal |
| **PySide2 (Qt)** | 5.15 | Framework de interfaz gráfica |
| **JSON** | - | Formato de persistencia de datos |
| **QtCore** | - | Funcionalidades base de Qt |
| **QtGui** | - | Componentes gráficos de Qt |
| **QtWidgets** | - | Widgets de interfaz de usuario |
| **QGraphicsScene** | - | Lienzo para dibujo |
| **math** | - | Cálculos matemáticos |
| **pprint** | - | Impresión estructurada de datos |
| **random** | - | Generación de números aleatorios |

---

## ⚙️ Requisitos previos

### Software Necesario
1. **Python 3.x** - [Descargar aquí](https://www.python.org/downloads/)
2. **PySide2** - Framework Qt para Python

### Dependencias de Python

```bash
# Instalación de dependencias
pip install PySide2
