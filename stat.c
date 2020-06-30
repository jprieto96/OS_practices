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

    printf("Tipo de fichero: ");
    if(S_ISREG(sb.st_mode)) printf("fichero regular\n");
    else if(S_ISDIR(sb.st_mode)) printf("directorio\n");
    else if(S_ISFIFO(sb.st_mode)) printf("FIFO/pipe\n");
    else if(S_ISLNK(sb.st_mode)) printf("enlace simbólico\n");
    else if(S_ISBLK(sb.st_mode)) printf("dispositivo de bloques\n");
    else if(S_ISCHR(sb.st_mode)) printf("dispositivo de caracteres\n");
    else if(S_ISSOCK(sb.st_mode)) printf("socket\n");
    else printf("¿¿¿¿¿¿¿¿????????\n");

    printf("Modo: %o (octal)\n", sb.st_mode);
    printf("I-node: %lld\n",  sb.st_ino);
    printf("Número de enlaces: %d\n",  sb.st_nlink);
    printf("Propietario: UID=%u GID=%u\n", sb.st_uid, sb.st_gid);
        printf("Tamaño bloque ideal para E/S: %d bytes\n",sb.st_blksize);
    printf("Tamaño fichero: %lld bytes\n", sb.st_size);
    printf("Bloques usados: %lld\n", sb.st_blocks);
    printf("Última modificación del estado: %s",
        ctime(&sb.st_ctime));
    printf("Último aceso: %s", ctime(&sb.st_atime));
    printf("Última modificación del fichero: %s",
            ctime(&sb.st_mtime));
    exit(0);
}
