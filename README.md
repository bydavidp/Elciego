# Elciego

Proyecto en C++ orientado a la gestión de inventario y operaciones de un negocio (por ejemplo, tienda o estudio fotográfico).  
El objetivo es practicar programación orientada a objetos, manejo de archivos de texto y separación en capas (`include/`, `src/`, `main.cpp`) usando CMake.

## Características

- Implementación en C++ con organización en módulos.
- Uso de archivos de texto para almacenar información (inventario, operaciones, etc.).
- Separación de interfaz principal (`main.cpp`) y lógica de negocio en `src/` y `include/`.
- Proyecto pensado para prácticas universitarias de POO y estructuras de datos.

## Estructura del proyecto

```bash
Elciego/
├── .idea/                  # Configuración del IDE (CLion, etc.)
├── include/                # Headers (.h / .hpp) con clases y funciones
├── src/                    # Implementación de clases y lógica
├── CMakeLists.txt          # Configuración del proyecto con CMake
├── main.cpp                # Punto de entrada del programa
├── Fotografos.txt          # Datos de fotógrafos (o entidades relacionadas)
├── inventarioelciego.txt   # Archivo de inventario
└── registroOperaciones.txt # Log de operaciones realizadas
```

> Las rutas y nombres se basan en los archivos visibles en el repositorio.

## Requisitos

- CMake (versión 3.10 o superior recomendada).
- Compilador C++ compatible con C++11 o superior (g++, clang, MSVC).
- Un IDE o editor de tu preferencia (CLion, VS Code, etc.).

## Compilación y ejecución

### Usando CMake desde terminal

```bash
# Clonar el repositorio
git clone https://github.com/bydavidp/Elciego.git
cd Elciego

# Crear carpeta de build
mkdir build
cd build

# Generar el proyecto con CMake
cmake ..

# Compilar
cmake --build .

# Ejecutar (nombre de ejecutable puede variar según CMakeLists)
./Elciego
```

En Windows, el ejecutable puede ser `Elciego.exe` y se ejecuta con:

```powershell
.\Elciego.exe
```

### Desde un IDE (por ejemplo CLion)

1. Abrir la carpeta del proyecto.
2. Permitir que el IDE detecte el `CMakeLists.txt`.
3. Configurar la target principal.
4. Compilar y ejecutar desde el IDE.

## Archivos de datos

El proyecto utiliza varios archivos de texto para persistir información:

- `Fotografos.txt`: listado de fotógrafos o entidades asociadas.
- `inventarioelciego.txt`: inventario de productos, servicios o recursos.
- `registroOperaciones.txt`: registro histórico de operaciones (altas, bajas, ventas, etc.).

La estructura exacta de cada archivo (campos, separadores, etc.) se define en el código fuente.  
Si modificas estos archivos manualmente, respeta el formato esperado para evitar errores de lectura.

## Objetivos de aprendizaje

Este proyecto sirve para practicar:

- Programación orientada a objetos en C++.
- Lectura y escritura de archivos de texto.
- Organización de proyectos con `include/` y `src/`.
- Uso básico de CMake para compilar proyectos C++.
- Diseño de menús y lógica de negocio en aplicaciones de consola.

## Próximas mejoras (ideas)

- Validación más robusta de entrada del usuario.
- Manejo de errores al leer/escribir archivos.
- Reportes más detallados (por ejemplo, resumen de inventario o ventas).
- Separar más la lógica de la interfaz de consola.
- Añadir tests unitarios para las clases principales.

## Cómo contribuir

Si quieres extender o mejorar el proyecto:

1. Haz un fork del repositorio.
2. Crea una rama nueva para tus cambios:
   ```bash
   git checkout -b feature/mimejora
   ```
3. Realiza los cambios y haz commits descriptivos.
4. Envía un pull request explicando la mejora.

## Autor

**David Palacios**  
Proyecto académico en C++ para practicar POO, manejo de archivos y estructuración de proyectos con CMake.