#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define BLOQUE 512

static void error(char* mensaje) {
   write(2, mensaje, strlen(mensaje));
   exit(1);
}

int main(int argc, char* argv[]) {
  int fd;
  char byte='A';

  if (argc != 3) 
    error("Argumentos no válidos\n");
  if ((fd = creat(argv[1], 0666)) < 0) 	
    error("No se puede crear el fichero\n");
  if (lseek(fd, atoi(argv[2]), SEEK_SET) < 0)
    error("No se puede posicionar en el fichero\n");
  else if (write(fd, &byte, 1) < 0)
    error("No se puede escribir en el fichero\n");
    
  close(fd);
}

