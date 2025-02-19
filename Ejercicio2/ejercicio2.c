#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio, fin;
    double tiempo_transcurrido;

    // Registrar el tiempo antes de los ciclos
    inicio = clock();

    // Tres ciclos for con un millón de iteraciones cada uno, mostrando el índice
    for (int i = 0; i < 1000000; i++) {
        printf("Iteración: %d\n", i);
    }
    for (int i = 0; i < 1000000; i++) {
        printf("Iteración: %d\n", i);
    }
    for (int i = 0; i < 1000000; i++) {
        printf("Iteración: %d\n", i);
    }

    // Registrar el tiempo después de los ciclos
    fin = clock();

    // Calcular el tiempo transcurrido en segundos
    tiempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;

    // Mostrar el resultado
    printf("Tiempo transcurrido: %f segundos\n", tiempo_transcurrido);

    return 0;
}
