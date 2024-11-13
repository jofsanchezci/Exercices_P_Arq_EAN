#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    pid_t pid1, pid2;

    // Crear el primer proceso hijo para ejecutar kcalc
    pid1 = fork();
    if (pid1 == 0) {
        // Proceso hijo 1: ejecutar kcalc
        execvp("kcalc", (char *[]){"kcalc", NULL});
        // Si execvp falla
        perror("Error al ejecutar kcalc");
        exit(1);
    } 

    // Crear el segundo proceso hijo para ejecutar xload
    pid2 = fork();
    if (pid2 == 0) {
        // Proceso hijo 2: ejecutar xload
        execvp("xload", (char *[]){"xload", NULL});
        // Si execvp falla
        perror("Error al ejecutar xload");
        exit(1);
    }

    // El proceso principal espera la finalización de ambos procesos hijos
    int status1, status2;
    waitpid(pid1, &status1, 0); // Esperar a que el primer hijo termine
    waitpid(pid2, &status2, 0); // Esperar a que el segundo hijo termine

    // Informar sobre la finalización de los procesos
    printf("El proceso kcalc terminó con el estado %d\n", status1);
    printf("El proceso xload terminó con el estado %d\n", status2);

    return 0;
}
