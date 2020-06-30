#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

pid_t pid_hijo;
static int TERMINADO = 0;

void proc_adios_padre()
{
    char resp[1];
    write(1, "¿Quieres que terminar? (s/n): ", 31);
    read(0, resp, 1);
    if(resp[0] == 's')
    {
        kill(pid_hijo, SIGUSR1);
        wait(&pid_hijo);
        write(1, "ADIOS\n", 6);
        TERMINADO = 1;
    }
}

int main()
{
    signal(SIGUSR2, proc_adios_padre);

    while(!TERMINADO) {
        printf("Hola hijo\n");
        pid_hijo = fork();
        if (pid_hijo == 0)
        {
            if (execlp("./adios-hijo","adios-hijo", NULL) == -1)
            {
                write(2, "Error en exec\n", 14);
                exit(1);
            }
        }
        pause();
    }
    
    exit(0);
}
