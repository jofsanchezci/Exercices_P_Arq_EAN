#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void print_process_hierarchy(int level, int i, int j) {
    // Imprimir el proceso actual con un nivel de profundidad
    printf("Nivel %d: Proceso (PID: %d) con i=%d y j=%d\n", level, getpid(), i, j);
}

int main() {
    pid_t pid;
    int i, j;
    int level = 0; // Nivel de profundidad en la jerarquía

    // Primer ciclo for (i = 0; i < 2; i++)
    for (i = 0; i < 2; i++) {
        pid = getpid(); // Obtener el PID del proceso actual
        print_process_hierarchy(level, i, 0); // Mostrar el proceso principal

        // Segundo ciclo for (j = 0; j < i + 2; j++)
        for (j = 0; j < i + 2; j++) {
            pid = fork(); // Crear un nuevo proceso

            if (pid != 0) {
                // Si estamos en el proceso padre
                print_process_hierarchy(level + 1, i, j);
                // Si el proceso padre crea otro hijo
                if (pid != 0) {
                    fork();
                }
                break; // Salir del ciclo interior en el proceso padre
            } else {
                // Si estamos en el proceso hijo
                print_process_hierarchy(level + 1, i, j);
                break; // Salir del ciclo interior en el proceso hijo
            }
        }
        // Verifica si es el proceso principal
        if (pid != getpid()) {
            break; // Salir del ciclo exterior en el proceso hijo
        }
    }
    return 0;
}
