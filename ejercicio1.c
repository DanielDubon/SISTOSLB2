#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Proceso padre (PID: %d)\n", getpid());

    fork();
    printf("Proceso (PID: %d, PPID: %d) después del primer fork()\n", getpid(), getppid());

    fork();
    printf("Proceso (PID: %d, PPID: %d) después del segundo fork()\n", getpid(), getppid());

    fork();
    printf("Proceso (PID: %d, PPID: %d) después del tercer fork()\n", getpid(), getppid());

    fork();
    printf("Proceso (PID: %d, PPID: %d) después del cuarto fork()\n", getpid(), getppid());

    return 0;
}
