#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



int main() {

    pid_t pid = fork();



    if (pid < 0) {
        perror("Error en fork");
        exit(EXIT_FAILURE);

    }



    if (pid == 0) { 

        execl("./ipc", "./ipc", "5", "B", NULL);
        exit(EXIT_FAILURE);

    } 



    wait(NULL);  
    return 0;

} 