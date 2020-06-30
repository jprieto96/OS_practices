#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  struct stat sb;

  if (argc != 2) {
      fprintf(stderr, "*** utiliza: %s <fichero>\n", argv[0]);
      exit(1);
  }
  
  if (stat(argv[1], &sb) == -1) {
      perror("stat");
      exit(0);
  }

  if (S_ISREG(sb.st_mode)) {
    printf("%s es un fichero\n", argv[1]);
    printf("Tamaño fichero: %lld bytes\n", sb.st_size);
    printf("Última modificación del estado: %s", ctime(&sb.st_ctime));
    printf("Último aceso: %s", ctime(&sb.st_atime));
    printf("Última modificación del fichero: %s", ctime(&sb.st_mtime));
  }  	 	
  else if (S_ISDIR(sb.st_mode))
          printf("%s es un directorio\n", argv[1]);

  /*PERMISOS PROPIETARIO*/
  if (((S_IRUSR)&(sb.st_mode))==(S_IRUSR)) 
    printf("con permiso de lectura para el propietario\n");
  else 
    printf("sin permiso de lectura para el propietario\n");
  if (((S_IWUSR)&(sb.st_mode))==(S_IWUSR)) 
    printf("con permiso de escritura para el propietario\n");
  else 
    printf("sin permiso de escritura para el propietario\n");
  if (((S_IXUSR)&(sb.st_mode))==(S_IXUSR)) 
    printf("con permiso de paso para el propietario\n");
  else 
    printf("sin permiso de paso para el propietario\n");

    /*PERMISOS GRUPO*/
  if (((S_IRGRP)&(sb.st_mode))==(S_IRGRP)) 
    printf("con permiso de lectura para el grupo\n");
  else 
    printf("sin permiso de lectura para el grupo\n");
  if (((S_IWGRP)&(sb.st_mode))==(S_IWGRP)) 
    printf("con permiso de escritura para el grupo\n");
  else 
    printf("sin permiso de escritura para el grupo\n");
  if (((S_IXGRP)&(sb.st_mode))==(S_IXGRP)) 
    printf("con permiso de paso para el grupo\n");
  else 
    printf("sin permiso de paso para el grupo\n");

  /*PERMISOS OTROS*/
  if (((S_IROTH)&(sb.st_mode))==(S_IROTH)) 
    printf("con permiso de lectura para otros\n");
  else 
    printf("sin permiso de lectura para otros\n");
  if (((S_IWOTH)&(sb.st_mode))==(S_IWOTH)) 
    printf("con permiso de escritura para otros\n");
  else 
    printf("sin permiso de escritura para otors\n");
  if (((S_IXOTH)&(sb.st_mode))==(S_IXOTH)) 
    printf("con permiso de paso para otros\n");
  else 
    printf("sin permiso de paso para otros\n");
          
  exit(0);
}
