#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char* argv[]) {
	int i, N;
	time_t t;
	N = atoi(argv[1]);
	for (i=0; i<N; i++)
		t =  time(NULL);
/*	printf("%d\n", i); */
	exit(0);
}
