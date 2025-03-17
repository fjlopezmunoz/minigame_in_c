# MiniProyecto-Videojuego en C con SDL2 "Rocas Picudas" - Instrucciones de Compilación

Este proyecto es una versión adaptada del mítico Space Invaders. Aquí se detallan los pasos necesarios para compilar y ejecutar la aplicación en **Windows** y **Linux (Fedora)**.

## Requisitos

### Windows
- **Code::Blocks** con MinGW (por ejemplo, `codeblocks-13.12mingw-setup.exe`).
- **SDL2** para Windows (por ejemplo, `SDL2-devel-2.0.3-mingw.tar.gz`).

### Linux (Fedora)
- **Code::Blocks** (opcional, también se puede compilar desde terminal).
- **SDL2** y **SDL2-devel** (instalados mediante el gestor de paquetes).
- **GCC** (incluido en la distribución).

---

## Compilación en Windows

1. **Descargar e instalar Code::Blocks:**
   - Descarga el instalador que incluya MinGW (ej.: `codeblocks-13.12mingw-setup.exe`) y sigue el proceso de instalación.

2. **Descargar y configurar SDL2:**
   - Descarga la versión de SDL2 para Windows (por ejemplo, `SDL2-devel-2.0.3-mingw.tar.gz`) y descomprímela.
   - Copia el archivo `SDL2.dll` (ubicado en `SDL2-2.0.3\i686-w64-mingw32\bin`) a las siguientes carpetas:
     - `C:\Windows\System32`
     - `C:\Windows\SysWOW64`
   - Copia el contenido de la carpeta `SDL2-2.0.3\i686-w64-mingw32\lib` a la carpeta de librerías de Code::Blocks:
     - `C:\Archivos de programa (x86)\CodeBlocks\MinGW\lib`
   - Copia la carpeta `SDL2` de `SDL2-2.0.3\i686-w64-mingw32\include` a la carpeta de includes:
     - `C:\Archivos de programa (x86)\CodeBlocks\MinGW\include`

3. **Configurar Code::Blocks:**
   - Abre Code::Blocks y carga o crea tu proyecto.
   - Ve a **Settings → Compiler...** y, en la pestaña **Compiler Settings**, agrega en **Other options**:
     ```
     -std=c99
     ```
   - En la pestaña **Linker Settings**, en **Other linker options**, agrega:
     ```
     -lmingw32 -lSDL2main -lSDL2
     ```
   - Verifica en la pestaña **Toolchain executables** que la ruta apunte al compilador MinGW de Code::Blocks (por ejemplo, `C:\Program Files (x86)\CodeBlocks\MinGW`).

4. **Compilar y ejecutar:**
   - Compila el proyecto y ejecuta la aplicación. Asegúrate de que `SDL2.dll` se encuentre en las rutas correctas para la ejecución.

---

## Compilación en Linux (Fedora)

1. **Instalar las dependencias:**
   Abre una terminal y ejecuta:
   ```bash
   sudo dnf install codeblocks SDL2 SDL2-devel
   ```
2. **(Opción 1) Usando Code::Blocks:**
   - Abre Code::Blocks y carga o crea tu proyecto.
   - Ve a **Settings → Compiler...** y, en la pestaña **Compiler Settings**, agrega en **Other options**:
     ```
     -std=c99
     ```
   - En la pestaña **Linker Settings**, en **Other linker options**, agrega:
     ```
     `sdl2-config --cflags --libs` -lm
     ```
    - Compila y ejecuta.

3. **(Opción 1) Usando make**
   - Con la termninal, encontrándose en el directorio raíz que contiene este repositorio ejecuta:
     ```bash
     make
     ```
   - Para eliminar los ficheros residuales de la compilación se puede usar también:
     ```bash
     make clean
     ```
   - Verifica en la pestaña **Toolchain executables** que la ruta apunte al compilador MinGW de Code::Blocks (por ejemplo, `C:\Program Files (x86)\CodeBlocks\MinGW`).
   - Ejecuta con:
     ```bash
     ./piedras_picudas
     ```
     Nota: Asegúrate de tener permisos de ejecución, de no tenerlos hacer:
     ```bash
     chmod +x piedras_picudas
     ```
   
