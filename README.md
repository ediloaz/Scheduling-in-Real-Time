# Proyecto 3

Del curso **Sistemas Operativos Avanzados**, de la Maestría de Ciencias de la Computación del Tecnológico de Costa Rica.

Profesor:
  Dr. Francisco Torres Rojas

Integrantes:
  - Nicole Carvajal Barboza 2017098785
  - Rubén González Villanueva 2017118764
  - Edisson López 2013103311
  - Otto Mena Kikut 2021582208
  - Cristina Soto Rojas 2021582215


# Compilar

Para compilar utilizar el siguiente comando:

 ```gcc -o interface interface.c -lm -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic latex.c ```
 
 Para ejecutar el programa:

 ```./interface ```

 Este programa no necesita parámetros, luego de su ejecución se abrirá un documento PDF con la solución del caso.