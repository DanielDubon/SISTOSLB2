#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();



    if (pid == 0) {
        for (int i = 1; i <= 8000000; i++) {
            printf("Hijo: %d\n", i);
        }
    } else {
        while (1);
    }
    return 0;
}
