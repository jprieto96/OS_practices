#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>


void ld(char nombre_dir[])
{
   DIR *dirp;
   struct dirent *dp;

   if ((dirp = opendir(nombre_dir))== NULL)
      printf("No se puede abrir el directorio %s\n", nombre_dir);
   else 
   {
      while ((dp = readdir(dirp)) != NULL) //lee entrada una entrada
            printf("%s\n", dp->d_name);
      closedir(dirp);
   }
}


int main(int argc, char *argv[])
{
    int i;
    if (argc == 1) ld(".");
    else
        for (i= 1; i< argc; i++) 
        {
            printf("********** %s ***********\n", argv[i]);
            ld(argv[i]);
        }

}
