# pipex42
This project is about handling pipes<br>

El proyecto de pipex en 42 Network es una tarea que tiene como objetivo implementar un programa similar al comando shell "pipe" (|) en Unix/Linux. El programa debe ser capaz de recibir cuatro argumentos: el nombre del archivo de entrada, el primer comando, el segundo comando y el nombre del archivo de salida. <br><br>

El programa debe leer el archivo de entrada, ejecutar el primer comando en los datos leídos, tomar su salida y pasarla como entrada al segundo comando, y finalmente escribir la salida del segundo comando en el archivo de salida.<br><br>

Además, el programa debe utilizar la función execve para ejecutar los comandos. También debe manejar cualquier error que pueda ocurrir, como errores en la lectura del archivo de entrada o en la escritura del archivo de salida.<br><br>

En términos de implementación, el proyecto se divide en varias partes:<br>

* Leer y validar los argumentos de entrada.
* Parsear los comandos y extraer sus argumentos.
* Buscar las rutas de los comandos en las variables de entorno PATH.
* Crear un pipeline de múltiples procesos hijos utilizando la llamada al sistema pipe().
* Redireccionar la entrada y la salida de los procesos hijos.
* Ejecutar los comandos en los procesos hijos utilizando la llamada al sistema execve().
* Esperar a que los procesos hijos terminen su ejecución.
* Manejar cualquier error que pueda ocurrir.<br>

En general, el proyecto requiere una buena comprensión de los conceptos de procesos, pipes, redirección de entrada/salida y llamadas al sistema en Unix/Linux. También es importante saber cómo trabajar con cadenas de caracteres y funciones de manejo de memoria en C.<br><br>

Conceptos básicos de procesos, pipes, redirección de entrada/salida y llamadas al sistema en Unix/Linux:<br>

Procesos:<br>

* En Unix/Linux, un proceso es una instancia de un programa en ejecución. Cada proceso tiene su propio espacio de memoria y se comunica con otros procesos a través de IPC (Inter Process Communication).
* Cada proceso se identifica por un número único llamado PID (Process ID).
* Los procesos pueden ser creados y controlados mediante llamadas al sistema como fork(), exec(), wait() y exit().<br>
* El pipe() es una función de sistema en C que se utiliza para crear una tubería o "pipe" que permite la comunicación unidireccional entre dos procesos. Una tubería consta de dos extremos, uno para escribir y otro para leer, y se utiliza para transferir datos desde un proceso al otro.

El pipe() toma un argumento de tipo puntero a un array de dos enteros, los cuales representan los dos extremos de la tubería, y devuelve 0 en caso de éxito y -1 en caso de error.

Por lo general, se utiliza junto con la función fork() para crear un proceso hijo y una tubería entre el proceso padre y el proceso hijo. El proceso padre escribe los datos en un extremo de la tubería y el proceso hijo los lee en el otro extremo. De esta manera, se puede compartir información entre los dos procesos.

Pipes:<br>

* Un pipe es un mecanismo de IPC que permite la comunicación unidireccional entre dos procesos.
* Los pipes se crean mediante la llamada al sistema pipe() y devuelven dos descriptores de archivo, uno para leer y otro para escribir.
* Los procesos pueden comunicarse a través de un pipe enviando datos a través del extremo de escritura y leyendo datos del extremo de lectura.<br>

Redirección de entrada/salida:<br>

* La redirección de entrada/salida permite a los procesos redirigir la entrada o salida estándar hacia o desde un archivo o dispositivo diferente.
* La redirección de entrada se realiza mediante la operación "<" y la redirección de salida mediante ">" o ">>".
* Los procesos pueden utilizar la redirección de entrada/salida para leer datos de un archivo en lugar del teclado o escribir datos en un archivo en lugar de la pantalla.<br>

Llamadas al sistema en Unix/Linux:<br>

* Unix/Linux es un sistema operativo basado en el kernel de Unix, que proporciona una interfaz de programación de aplicaciones (API) para los programas.
* Los programas interactúan con el kernel a través de llamadas al sistema, que son funciones del kernel que los programas pueden llamar para realizar tareas como la creación de procesos, la lectura y escritura de archivos, la comunicación entre procesos y la gestión de recursos del sistema.
* Las llamadas al sistema en Unix/Linux se realizan mediante una sintaxis específica de la función y un número de sistema que identifica la función.
* Espero que esta explicación te haya sido útil. ¡Buena suerte con tu proyecto!
