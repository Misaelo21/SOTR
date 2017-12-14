#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

jmp_buf env; /*Esta variable debe ser global para que la conozcan las
               rutinas de tratamiento de señales*/

/***
    main: Se encarga de armar la señal SIGUSR1 y de establecer puntos de
    repligue.
***/

//     https://github.com/Misaelo21/SOTR.git

void main(){
    void manejador_SIGUSR1();
    int i;

    signal(SIGUSR1, manejador_SIGUSR1);

    for(i = 0; i < 100; i++){
        if(setjmp(env) == 0){
            printf("Punto de repliegue en el estado %d\n", i);
        } else {
            printf("Regreso al punto de repliegue del estado %d\n", i);
        }
        sleep(5);
    }
}

/***
    manejador_SIGUSR1: se encarga de restaurar el proceso a alguno de los
    estados previos guardados en la variable global env.
***/

void manejador_SIGUSR1(int sig){
    signal(SIGUSR1, manejador_SIGUSR1);
    longjmp(env, 1);
}
