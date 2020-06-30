#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void proc_adios_hijo()
{
    write(1, "HASTA PRONTO\n", 13);
    exit(0);
}

int main()
{
    signal(SIGUSR1, proc_adios_hijo);

    printf("Hola padre\n");
    kill(getppid(), SIGUSR2);

    pause();
}
