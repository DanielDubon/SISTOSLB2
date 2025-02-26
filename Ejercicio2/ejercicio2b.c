#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    clock_t inicio, fin;
    pid_t pid_hijo, pid_nieto, pid_bisnieto;
    double tiempo_transcurrido;

    // Tomar el tiempo antes del fork
    inicio = clock();

    pid_hijo = fork(); // Primer fork (crea al hijo)

    if (pid_hijo == 0) { // Código del hijo
        pid_nieto = fork(); // Segundo fork (crea al nieto)

        if (pid_nieto == 0) { // Có(digo del nieto
            pid_bisnieto = fork(); // Tercer fork (crea al bisnieto)

            if (pid_bisnieto == 0) { // Código del bisnieto
                for (int i = 0; i < 1000000; i++) {
                    printf("Bisnieto - Iteración: %d\n", i);
                }
                return 0;
            } else {
                wait(NULL); // El nieto espera al bisnieto
                for (int i = 0; i < 1000000; i++) {
                    printf("Nieto - Iteración: %d\n", i);
                }
                return 0;
            }
        } else {
            wait(NULL); // El hijo espera al nieto
            for (int i = 0; i < 1000000; i++) {
                printf("Hijo - Iteración: %d\n", i);
            }
            return 0;
        }
    } else {
        wait(NULL); // El padre espera al hijo
        fin = clock(); // Tomar el tiempo después de que el hijo termine

        // Calcular el tiempo transcurrido en segundos
        tiempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;

        // Mostrar el resultado
        printf("Tiempo transcurrido: %f segundos\n", tiempo_transcurrido);
    }

    return 0;
}
