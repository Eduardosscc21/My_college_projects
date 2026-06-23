# 📚 Sistema de Gestión de Tesis y Artículos - Estructura de Datos

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![C++](https://img.shields.io/badge/c++-11-green)
![Status](https://img.shields.io/badge/status-completed-brightgreen)
![Files](https://img.shields.io/badge/file_handling-6_methods-orange)
![DataStructures](https://img.shields.io/badge/data-structures-purple)

> Sistema integral de gestión de información académica (tesis, artículos, alumnos, profesores) implementando 6 técnicas diferentes de organización y acceso a archivos en C++.

---

## 📋 Tabla de Contenidos
- [Descripción](#-descripción)
- [Características](#-características)
- [Tecnologías Utilizadas](#-tecnologías-utilizadas)
- [Requisitos Previos](#-requisitos-previos)
- [Arquitectura del Sistema](#-arquitectura-del-sistema)


## 📖 Descripción

Este proyecto fue desarrollado para la materia de **Estructura de Datos**. El sistema implementa **seis técnicas diferentes de organización y acceso a archivos** para gestionar información académica de la Universidad de Guadalajara (UDG), incluyendo tesis, artículos, alumnos, profesores e historiales de consultas.

### 🎯 Objetivos del Sistema

- ✅ Implementar **6 técnicas de organización de archivos**: Delimitadores, Campos de Dimensión, Acceso Directo, Índice Simple, Serialización y Dispersión
- ✅ Gestionar información académica de la UDG
- ✅ Proporcionar operaciones CRUD (Crear, Leer, Actualizar, Eliminar) para cada técnica
- ✅ Comparar el rendimiento y características de cada método de organización
- ✅ Demostrar conceptos fundamentales de estructura de datos en archivos

### 🎓 Contexto Académico

- **Materia**: Estructura de Datos
- **Temas aplicados**: 
  - Organización de archivos
  - Métodos de acceso (secuencial, directo, indexado)
  - Técnicas de dispersión (hashing)
  - Serialización de objetos
  - Manejo de registros de longitud fija y variable
  - Índices y archivos de datos

---

## ✨ Características

| Módulo | Técnica | Operaciones | Archivo |
|--------|---------|-------------|---------|
| 📄 **Tesis** | Delimitadores | CRUD completo | `Tesis.txt` |
| 📑 **Artículos** | Campos de Dimensión | CRUD completo | `Articulos.txt` |
| 👨‍🎓 **Alumnos** | Acceso Directo | CRUD completo | `Alumnos.txt` |
| ⭐ **Populares** | Índice Simple | CRUD + Índice | `datos.txt` / `indice.txt` |
| 📊 **Historial** | Serialización | CRUD completo | `historial.txt` |
| 👨‍🏫 **Profesor** | Dispersión (Hashing) | CRUD completo | `dispersion2.txt` |

---

## 🛠️ Técnicas de Organización Implementadas

### 1. Delimitadores (Delimitadores.hpp)
- **Descripción**: Los campos de cada registro están separados por un carácter delimitador (`|`)
- **Ventajas**: Fácil de implementar, legible por humanos
- **Desventajas**: Lectura carácter por carácter, menos eficiente

### 2. Campos de Dimensión (Campos_de_dimension.hpp)
- **Descripción**: Cada campo almacena su longitud seguida del contenido
- **Ventajas**: Campos de longitud variable, eficiente en espacio
- **Desventajas**: Mayor complejidad de implementación

### 3. Acceso Directo (Acceso_directo.hpp)
- **Descripción**: Registros de longitud fija, acceso directo por posición
- **Ventajas**: Rápido acceso aleatorio, simple de implementar
- **Desventajas**: Desperdicio de espacio si los campos son cortos

### 4. Índice Simple (Indice_simple.hpp)
- **Descripción**: Archivo de datos + Archivo de índices (llave + posición)
- **Ventajas**: Búsqueda rápida, soporta ordenamiento
- **Desventajas**: Mantenimiento adicional del índice

### 5. Serialización (Serializacion.hpp)
- **Descripción**: Guarda objetos completos en archivos binarios
- **Ventajas**: Preserva toda la estructura del objeto, eficiente
- **Desventajas**: No legible por humanos, dependiente de la arquitectura

### 6. Dispersión / Hashing (Dispersion.hpp)
- **Descripción**: Función hash para determinar ubicación del registro
- **Ventajas**: Acceso O(1) promedio, manejo de colisiones
- **Desventajas**: Función hash crítica, reorganización compleja

---

## 🛠️ Tecnologías Utilizadas

| Tecnología | Propósito |
|------------|-----------|
| **C++** | Lenguaje de programación principal |
| **STL** | Biblioteca estándar de C++ |
| **fstream** | Manejo de archivos (lectura/escritura) |
| **cstring** | Manejo de cadenas de caracteres |
| **conio.h** | Funciones de entrada/salida en consola |
| **stdlib.h** | Funciones del sistema (system, remove, rename) |

---

## ⚙️ Requisitos Previos

### Software Necesario
1. **Compilador C++** (g++ / MinGW / Visual Studio)
2. **Sistema Operativo**: Windows (uso de `system("cls")` y `system("pause")`)

### Estructura de Archivos
El sistema crea y utiliza los siguientes archivos en el directorio de ejecución:
- `Tesis.txt` - Archivo con delimitadores
- `Articulos.txt` - Archivo con campos de dimensión
- `Alumnos.txt` - Archivo de acceso directo
- `datos.txt` / `indice.txt` - Archivos de índice simple
- `historial.txt` - Archivo serializado
- `dispersion2.txt` - Archivo de dispersión

---

### Archivos del Proyecto

```
📦 estructura-datos-udg/
 ┣━━ 📄 proyecto.cpp              # Archivo principal
 ┣━━ 📄 Delimitadores.hpp         # Técnica 1: Delimitadores
 ┣━━ 📄 Campos_de_dimension.hpp   # Técnica 2: Campos de Dimensión
 ┣━━ 📄 Acceso_directo.hpp        # Técnica 3: Acceso Directo
 ┣━━ 📄 Indice_simple.hpp         # Técnica 4: Índice Simple
 ┣━━ 📄 Serializacion.hpp         # Técnica 5: Serialización
 ┣━━ 📄 Dispersion.hpp            # Técnica 6: Dispersión
 ┣━━ 📄 README.md                 # Documentación
 ┣━━ 📁 screenshots/              # Capturas de pantalla
 ┃    ┣━━ 🖼️ menu_principal.png
 ┃    ┣━━ 🖼️ tesis_menu.png
 ┃    ┣━━ 🖼️ articulos_menu.png
 ┃    ┣━━ 🖼️ alumnos_menu.png
 ┃    ┣━━ 🖼️ populares_menu.png
 ┃    ┣━━ 🖼️ historial_menu.png
 ┃    ┗━━ 🖼️ profesor_menu.png
 ┗━━ 📁 data/                     # Archivos de datos
      ┣━━ 📄 Tesis.txt
      ┣━━ 📄 Articulos.txt
      ┣━━ 📄 Alumnos.txt
      ┣━━ 📄 datos.txt
      ┣━━ 📄 indice.txt
      ┣━━ 📄 historial.txt
      ┗━━ 📄 dispersion2.txt
```
