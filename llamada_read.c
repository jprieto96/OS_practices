#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
 
int main (void) {
        char* mensaje = "Hola, mundo! ¿Qué tal?\n";
        char respuesta[120]; 
        write (STDOUT_FILENO, mensaje, strlen(mensaje));
        read (STDIN_FILENO, respuesta, 120);
        exit(0);
}

