# Sistema Experto de Recomendación de Videojuegos

![Prolog](https://img.shields.io/badge/Prolog-Sistema%20Experto-red)
![Knowledge Based System](https://img.shields.io/badge/Sistemas%20Basados%20en%20Conocimiento-Académico-blue)

Sistema experto desarrollado en Prolog para la recomendación inteligente de videojuegos mediante inferencia lógica basada en preferencias, características de los juegos y perfiles de usuario.

---

# 📋 Tabla de contenidos

* Descripción
* Características
* Tecnologías utilizadas
* Requisitos previos

---

# 📖 Descripción

Este proyecto fue desarrollado como trabajo final para la materia de Seminario de sistemas basados en conocimiento.

El sistema utiliza una base de conocimiento compuesta por videojuegos, géneros, categorías y rangos de precios para generar recomendaciones personalizadas mediante reglas de inferencia escritas en Prolog.

A partir de las preferencias proporcionadas por el usuario, el sistema es capaz de identificar automáticamente los videojuegos que cumplen con las características solicitadas, simulando el comportamiento de un sistema experto basado en reglas.

## 🎯 Objetivos del sistema

* Representar conocimiento mediante hechos y reglas.
* Implementar mecanismos de inferencia lógica.
* Recomendar videojuegos según preferencias del usuario.
* Clasificar juegos por género, categoría y precio.
* Aplicar técnicas de razonamiento basadas en conocimiento.
* Simular el comportamiento de un sistema experto.

## 🎓 Contexto académico

**Materia:** Seminario de sistemas basados en conocimiento

### Temas aplicados

* Sistemas expertos.
* Bases de conocimiento.
* Representación del conocimiento.
* Inferencia lógica.
* Programación lógica.
* Reglas de producción.
* Sistemas de recomendación.
* Encadenamiento de reglas.
* Inteligencia Artificial simbólica.

---

# ✨ Características

| Módulo                       | Funcionalidad   | Descripción                           |
| ---------------------------- | --------------- | ------------------------------------- |
| 🎮 Base de Juegos            | Conocimiento    | Almacena información de videojuegos   |
| 🏷️ Géneros                  | Clasificación   | Organización por género               |
| 📂 Categorías                | Clasificación   | Organización por características      |
| 💰 Precios                   | Segmentación    | Clasificación por costo               |
| 🧠 Motor de Inferencia       | Razonamiento    | Evalúa reglas y preferencias          |
| 🔍 Búsqueda Inteligente      | Consulta        | Recomienda juegos personalizados      |
| 👤 Perfiles de Usuario       | Especialización | Recomendaciones según tipo de jugador |
| 🎯 Búsqueda Avanzada         | Filtrado        | Combinación de múltiples criterios    |
| ♻️ Recomendaciones Similares | Sugerencias     | Propone alternativas relacionadas     |

---

# 🧠 Base de conocimiento

La base de conocimiento contiene información sobre:

### Videojuegos

* Más de 50 videojuegos registrados.
* Juegos gratuitos y de pago.
* Juegos multijugador y para un solo jugador.

### Géneros

* Acción
* Aventura
* RPG
* Estrategia
* Deportes
* Carreras
* Simulación
* Indie
* Casual
* Horror

### Categorías

* Multiplayer
* Singleplayer
* Coop
* PvP
* MMO
* CrossPlatform
* Steam Workshop
* Controller Support
* Steam Achievements

### Rangos de precio

* Gratis
* Económico
* Precio medio
* Premium

---

# 🤖 Perfiles expertos implementados

| Perfil         | Características                         |
| -------------- | --------------------------------------- |
| 🏆 Competitivo | Juegos gratuitos, PvP y multijugador    |
| 😌 Casual      | Juegos sencillos y accesibles           |
| 📖 Historia    | Experiencias narrativas para un jugador |
| 👥 Amigos      | Juegos cooperativos                     |
| 🎨 Indie       | Juegos independientes                   |
| 🔥 Hardcore    | RPGs complejos y experiencias premium   |

---

# 🔍 Ejemplos de consultas

### Buscar juegos para jugadores competitivos

```prolog
para_competitivo(Juego).
```

### Buscar juegos casuales

```prolog
para_casual(Juego).
```

### Buscar juegos para jugar con amigos

```prolog
para_amigos(Juego).
```

### Buscar juegos según preferencias específicas

```prolog
buscar_juego(gratis, gratis, multijugador, accion, Juego).
```

### Obtener alternativas gratuitas

```prolog
alternativa_gratis(JuegoPago, JuegoGratis).
```

---

# 🛠️ Tecnologías utilizadas

| Tecnología           | Versión    | Propósito                          |
| -------------------- | ---------- | ---------------------------------- |
| Prolog               | SWI-Prolog | Motor lógico                       |
| Programación Lógica  | -          | Implementación del sistema experto |
| Base de Conocimiento | -          | Almacenamiento de hechos           |
| Reglas de Inferencia | -          | Motor de razonamiento              |

---

# ⚙️ Requisitos previos

Antes de ejecutar el proyecto asegúrate de tener instalado:

### Software necesario

* SWI-Prolog

Descarga oficial:

https://www.swi-prolog.org

---

# 🚀 Ejecución del proyecto

Abrir SWI-Prolog y cargar el archivo:

```prolog
consult('SistemaExpertoJuegos.pl').
```

Posteriormente ejecutar cualquiera de las consultas definidas por el sistema.

---

# 📚 Arquitectura del sistema

### Hechos

Representan el conocimiento almacenado:

* juego()
* genero()
* categoria()
* precio()

### Reglas

Implementan la lógica de inferencia:

* juego_ideal()
* cumple_preferencia()
* buscar_juego()
* alternativa_gratis()
* si_te_gusta()

### Consultas

Permiten obtener recomendaciones basadas en el razonamiento del sistema.

---



