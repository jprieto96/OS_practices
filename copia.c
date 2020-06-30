#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BLOQUE 9192

static void error(char* mensaje) {
  write(2, mensaje, strlen(mensaje));
  exit(1);
}

int main(int argc, char* argv[]) {
  int tbloque, leidos, escritos, origen, destino;
  char buf[MAX_BLOQUE];

  if (argc != 4) error("Argumentos no válidos\n");
  else tbloque=atoi(argv[3]);
  if ((origen = open(argv[1], O_RDONLY)) < 0)
    error("No se puede abrir el fichero origen\n");
  if ((destino = creat(argv[2], 0644)) < 0) {
    close(origen);
    error("No se puede abrir el fichero destino\n");
  }

  while ((leidos = read(origen, buf, tbloque)) > 0) {
    if((escritos = write(destino, buf, leidos)) < 0) {
        close(origen); close(destino);
        error("Error al escribir\n");   
      }
  }

  if (leidos < 0) {
    close(origen); close(destino);
    error("Error al leer\n");  
  }

  close(origen); close(destino);
  exit(0);
}
