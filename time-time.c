#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char* argv[]) {
       int i, N;
       time_t t1, t2;

       N = atoi(argv[1]); 
       t1 = time(NULL);
       printf("%d : %s\n", i, asctime(gmtime(&t1)));

       for (i=0; i<N; i++) 
           time(NULL); 
           
       t2 =  time(NULL);
       printf("%d : %s\n", i, asctime(gmtime(&t2))); 	
       exit(0);
} 
