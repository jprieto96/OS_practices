#include <stdlib.h>

void proc_nada (void) {};

int main (int argc, char* argv[]) {
	int i, N;
	N = atoi(argv[1]);
	for (i=0; i<N; i++) proc_nada();
	exit(0);
}

