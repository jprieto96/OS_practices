#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int tab = 0;
int i;

void ldr(char nombre_dir[])
{
   DIR *dirp;
   struct dirent *dp;
   struct stat sb;
   char fichero [PATH_MAX];

   if ((dirp = opendir(nombre_dir))== NULL)
        printf("%s no se puede abrir \n", nombre_dir);
   else 
   {
        while ((dp = readdir(dirp)) != NULL)  {
            if ((strcmp (dp->d_name, ".") != 0) 
            && (strcmp (dp->d_name, "..") != 0)) {     
                for (i = 0; i < tab; i ++) printf("   ");
                    printf ("%s\n", dp->d_name);
                sprintf (fichero, "%s/%s", nombre_dir, dp->d_name);
                if (stat(fichero, &sb) == -1) {
                    printf("No se abre stat %s\n", fichero); 
                    exit(1);
                }
        
                if ((sb.st_mode & S_IFMT) == S_IFDIR) {
                    tab++;
                    ldr(fichero);
                    tab--;
                }
            }
        }
  }
  closedir(dirp);
}


int main(int argc, char *argv[])
{
    int i;
    if (argc == 1) ldr(".");
    else
        for (i= 1; i< argc; i++) 
        {
            printf("********** %s ***********\n", argv[i]);
            ldr(argv[i]);
        }
}
