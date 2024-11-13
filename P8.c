#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void crear_arbol(int prof, int anch, int nivel_actual) {
    pid_t pid;
    int i;

    // Si el nivel actual es mayor que la profundidad, terminamos la recursión
    if (nivel_actual > prof) {
        return;
    }

    // Imprimir información sobre el proceso actual
    printf("Nivel %d: Soy el proceso %d y mi padre es %d\n", nivel_actual, getpid(), getppid());

    // Si estamos en un nivel par (y distinto de cero), expandimos en anchura
    if (nivel_actual % 2 == 0 && nivel_actual != 0) {
        for (i = 0; i < anch; i++) {
            pid = fork();  // Crear un nuevo proceso
            if (pid == 0) {
                // Si es el hijo, entramos a la siguiente profundidad
                crear_arbol(prof, anch, nivel_actual + 1);
                exit(0);  // Terminamos el hijo después de crear los procesos hijos
            }
        }
    } else {
        // Si no es un nivel par (distinto de cero), solo creamos un proceso
        crear_arbol(prof, anch, nivel_actual + 1);
    }
}

int main(int argc, char *argv[]) {
    int prof, anch;

    // Verificar que el número de parámetros sea correcto
    if (argc != 3) {
        printf("Uso: %s <profundidad> <anchura>\n", argv[0]);
        exit(1);
    }

    prof = atoi(argv[1]);  // Convertir la profundidad desde el argumento
    anch = atoi(argv[2]);  // Convertir la anchura desde el argumento

    // Llamar a la función recursiva para crear el árbol de procesos
    crear_arbol(prof, anch, 0);

    // Pausar para evitar que los procesos terminen antes de que el árbol se imprima
    sleep(2);
    return 0;
}
