#include <unistd.h>
#include <stdlib.h>
#include <time.h>

time_t  time_funcion(time_t *t){return 0;};  

int main (int argc, char* argv[]) {
	int i, N;
	time_t t;
	N = atoi(argv[1]);
	for (i=0; i<N; i++) 
		t =  time_funcion(NULL);
	exit(0);
}

