#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Proceso padre (PID: %d)\n", getpid());

    for (int i = 0; i < 4; i++) {
        fork();
        printf("Proceso (PID: %d, PPID: %d) después del %d fork()\n", getpid(), getppid(), i+1);
    
    }
    return 0;
}
