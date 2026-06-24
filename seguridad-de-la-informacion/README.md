# Web Crawler 

![Python](https://img.shields.io/badge/Python-3.x-blue)
![Tkinter](https://img.shields.io/badge/Tkinter-GUI-green)
![Security](https://img.shields.io/badge/Seguridad%20de%20la%20Información-Académico-orange)

Sistema de escritorio desarrollado en Python para realizar búsquedas automatizadas de palabras clave dentro de sitios web, permitiendo monitoreo periódico, análisis de contenido y almacenamiento de resultados para seguimiento y auditoría.

---

# 📋 Tabla de contenidos

* Descripción
* Características
* Tecnologías utilizadas
* Requisitos previos

---

# 📖 Descripción

Este proyecto fue desarrollado como trabajo final para la materia de Seguridad de la Información. El sistema permite monitorear páginas web mediante la búsqueda de palabras clave específicas, facilitando la detección de cambios o apariciones de información relevante dentro de un sitio web.

La aplicación incorpora validación de URLs, programación de búsquedas automáticas, almacenamiento histórico de resultados y una interfaz gráfica amigable para el usuario.

## 🎯 Objetivos del sistema

* Automatizar la búsqueda de información dentro de páginas web.
* Monitorear la aparición de palabras clave específicas.
* Registrar resultados para auditoría y seguimiento.
* Validar entradas para reducir errores de procesamiento.
* Facilitar el análisis de contenido web mediante una interfaz gráfica.
* Implementar mecanismos de monitoreo periódico automatizado.

## 🎓 Contexto académico

**Materia:** Seguridad de la Información

### Temas aplicados

* Recolección automatizada de información.
* Monitoreo de contenido web.
* Validación de entradas.
* Gestión de registros (logs).
* Automatización de tareas.
* Procesamiento de información.
* Manejo seguro de datos obtenidos de Internet.
* Auditoría mediante almacenamiento histórico.

---

# ✨ Características

| Módulo                | Funcionalidad | Descripción                                         |
| --------------------- | ------------- | --------------------------------------------------- |
| 🌐 URL Validator      | Validación    | Verifica que las URLs ingresadas sean válidas       |
| 🔍 Keyword Search     | Búsqueda      | Localiza palabras clave dentro del contenido web    |
| 🎨 Highlight          | Resaltado     | Destaca visualmente las coincidencias encontradas   |
| 📄 Content Analysis   | Procesamiento | Analiza encabezados y párrafos del sitio            |
| ⏱️ Monitoring         | Seguimiento   | Permite búsquedas automáticas programadas           |
| 📊 Results Viewer     | Visualización | Presenta resultados dentro de la interfaz           |
| 💾 CSV Logging        | Auditoría     | Guarda búsquedas y resultados en archivo CSV        |
| 🧵 Multithreading     | Rendimiento   | Evita bloqueos de la interfaz durante las búsquedas |
| 🛑 Monitoring Control | Gestión       | Permite iniciar y detener el monitoreo              |

---

# 🛠️ Tecnologías utilizadas

| Tecnología     | Versión  | Propósito                          |
| -------------- | -------- | ---------------------------------- |
| Python         | 3.x      | Lenguaje de programación principal |
| Tkinter        | -        | Interfaz gráfica de usuario        |
| Requests       | 2.x      | Obtención de contenido web         |
| BeautifulSoup4 | 4.x      | Procesamiento y análisis HTML      |
| Validators     | -        | Validación de URLs                 |
| Schedule       | -        | Programación de tareas periódicas  |
| CSV            | Estándar | Almacenamiento de resultados       |
| Threading      | Estándar | Ejecución concurrente              |

---

# ⚙️ Requisitos previos

Antes de ejecutar el proyecto, asegúrate de tener instalado:

## Software necesario

* Python 3.x

## Dependencias de Python

```bash
pip install requests
pip install beautifulsoup4
pip install validators
pip install schedule
```

---

# 🚀 Ejecución del proyecto

Ejecutar el archivo principal:

```bash
python webcrawler.py
```

---

# 📚 Funcionamiento del sistema

1. El usuario ingresa una URL válida.
2. Introduce una palabra clave para buscar.
3. El sistema descarga el contenido HTML de la página.
4. Se analizan encabezados y párrafos.
5. Las coincidencias encontradas se resaltan visualmente.
6. Se contabilizan las apariciones de la palabra clave.
7. Los resultados se almacenan en un archivo CSV.
8. Opcionalmente se configura un monitoreo periódico automático.

---

# 🔐 Aspectos de seguridad aplicados

* Validación de URLs antes de procesar solicitudes.
* Manejo de excepciones para evitar fallos inesperados.
* Registro histórico de actividades.
* Automatización controlada mediante intervalos configurables.
* Separación entre interfaz gráfica y procesos de búsqueda mediante hilos.

---



Proyecto académico desarrollado para la materia de Seguridad de la Información.

