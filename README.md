# Registro Académico de Estudiantes

## Descripción
Este programa, desarrollado en lenguaje C, permite gestionar el registro académico de estudiantes mediante diversas funcionalidades, como registrar nuevos estudiantes, consultar información y borrar registros. El sistema utiliza archivos para almacenar los datos y una interfaz en consola para interactuar con el usuario.

## Funcionalidades Principales
1. **Registrar Estudiantes**:
   - Solicita el número de documento, nombre, y las notas de Matemáticas, Química, Biología e Informática.
   - Calcula el promedio de las notas.
   - Guarda la información en un archivo llamado `registro.txt`.

2. **Consultar Información**:
   - Permite buscar un estudiante por su número de documento.
   - Muestra la información del estudiante si existe en el registro.

3. **Borrar Registro Académico**:
   - Elimina los datos de un estudiante del archivo `registro.txt` usando su número de documento.

## Detalles Técnicos
### Bibliotecas Utilizadas
- **`<stdio.h>`**: Funciones estándar de entrada y salida, como `printf` y `scanf`.
- **`<windows.h>`**: Funciones para manipular la consola en sistemas Windows.
- **`<stdbool.h>`**: Soporte para tipos de datos booleanos (`true` y `false`).
- **`<string.h>`**: Funciones para manipulación de cadenas, como búsqueda y comparación.

### Estructura del Código
#### **Constante Definida**
- `#define Tam_Nom 10`: Tamaño máximo del nombre de un estudiante.

#### **Prototipos de Funciones**
- `gotoxy(x, y)`: Mueve el cursor de la consola a las coordenadas `(x, y)`.
- `clearScreen()`: Limpia la pantalla de la consola.
- `opcion()`: Muestra el menú principal y devuelve la opción seleccionada.
- `registrarEstudiante()`: Permite ingresar y guardar información de nuevos estudiantes.
- `verInfoEstudiante()`: Consulta y muestra información de un estudiante.
- `borrarRegistroAcademico()`: Elimina un registro de estudiante por documento.

#### **Estructura del Programa**
1. **`main()`**:
   - Establece el color de la consola.
   - Presenta el menú principal al usuario y llama a la función correspondiente según la opción seleccionada.

2. **Funciones Auxiliares**:
   - `gotoxy(int x, int y)`: Utiliza `windows.h` para posicionar el cursor.
   - `clearScreen()`: Usa `system("cls")` para limpiar la consola.

3. **Gestión de Estudiantes**:
   - **Registro**: Solicita datos del estudiante, calcula promedio y los guarda en un archivo.
   - **Consulta**: Busca por número de documento y muestra información si existe.
   - **Borrado**: Elimina un registro del archivo si coincide con el documento proporcionado.

### Almacenamiento de Datos
- Los datos de los estudiantes se guardan en un archivo de texto llamado `registro.txt`.
- Cada registro contiene:
  - Número de documento.
  - Nombre.
  - Notas en cuatro materias.
  - Promedio de las notas.

## Cómo Ejecutar el Programa
1. **Requisitos**:
   - Sistema operativo Windows.
   - Compilador compatible con C (e.g., MinGW o Visual Studio).

2. **Compilación**:
   - Compila el programa con un compilador de C:
     ```bash
     gcc -o registro_academico registro_academico.c
     ```

3. **Ejecución**:
   - Ejecuta el archivo compilado:
     ```bash
     ./registro_academico
     ```

4. **Navegación**:
   - Selecciona una opción del menú principal:
     - `1`: Registrar un estudiante.
     - `2`: Consultar información de un estudiante.
     - `3`: Borrar un registro.
     - `4`: Salir.

## Mejoras Posibles
- **Portabilidad**: Reemplazar funciones dependientes de Windows (`windows.h`) para compatibilidad con otros sistemas operativos.
- **Validaciones**: Agregar validaciones para datos ingresados (e.g., rango de notas, nombres válidos).
- **Interfaz Mejorada**: Implementar un menú gráfico con bibliotecas como `ncurses`.
- **Gestión Avanzada**: Introducir estructuras como árboles o listas enlazadas para manejo dinámico de registros.

## Autor
- **Juan David Fajardo Betancourt**  
  Universidad Nacional de Colombia.

---

**Nota**: Este README documenta las funcionalidades y estructura de un programa ya implementado para la gestión académica de estudiantes.
