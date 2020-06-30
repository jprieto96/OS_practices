#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{
   DIR *dirp;
   struct dirent *dp;

   if ((dirp = opendir(argv[1]))== NULL)
      printf("No se puede abrir el directorio %s\n", argv[1]);
   else 
   {    
      while ((dp = readdir(dirp)) != NULL) //lee una entrada
            printf("%s\n", dp->d_name);
      closedir(dirp);  
   }
}
