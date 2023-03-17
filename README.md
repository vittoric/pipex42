# pipex42
This project is about handling pipes
El proyecto de pipex en 42 Network es una tarea que tiene como objetivo implementar un programa similar al comando shell "pipe" (|) en Unix/Linux. El programa debe ser capaz de recibir cuatro argumentos: el nombre del archivo de entrada, el primer comando, el segundo comando y el nombre del archivo de salida.

El programa debe leer el archivo de entrada, ejecutar el primer comando en los datos leídos, tomar su salida y pasarla como entrada al segundo comando, y finalmente escribir la salida del segundo comando en el archivo de salida.

Además, el programa debe utilizar la función execve para ejecutar los comandos. También debe manejar cualquier error que pueda ocurrir, como errores en la lectura del archivo de entrada o en la escritura del archivo de salida.

En términos de implementación, el proyecto se divide en varias partes:

* Leer y validar los argumentos de entrada.
* Parsear los comandos y extraer sus argumentos.
* Buscar las rutas de los comandos en las variables de entorno PATH.
* Crear un pipeline de múltiples procesos hijos utilizando la llamada al sistema pipe().
* Redireccionar la entrada y la salida de los procesos hijos.
* Ejecutar los comandos en los procesos hijos utilizando la llamada al sistema execve().
* Esperar a que los procesos hijos terminen su ejecución.
* Manejar cualquier error que pueda ocurrir.
En general, el proyecto requiere una buena comprensión de los conceptos de procesos, pipes, redirección de entrada/salida y llamadas al sistema en Unix/Linux. También es importante saber cómo trabajar con cadenas de caracteres y funciones de manejo de memoria en C.
