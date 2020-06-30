#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
 
int main (void) {
        char* mensaje = "Hola, mundo!\n";
        write (STDOUT_FILENO, mensaje, strlen(mensaje));
        exit(0);
}

