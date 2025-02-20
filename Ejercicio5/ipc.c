#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>


#define SHM_NAME "/shared_mem_ipc"
#define MEM_SIZE 128



int main(int argc, char **argv) {

    if (argc != 3) {

        fprintf(stderr, "Se debe usar asi: %s <número> <caracter>\n", argv[0]);

        exit(EXIT_FAILURE);

    }

    int n = atoi(argv[1]);
    char x = argv[2][0];
    int shm_fd;
    char *shm_ptr;

    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);

    if (shm_fd == -1) {

        perror("Paso un error al abrir la memoria compartida");

        exit(EXIT_FAILURE);

    }



    if (ftruncate(shm_fd, MEM_SIZE) == -1) {
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);

    }



    shm_ptr = mmap(0, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    if (shm_ptr == MAP_FAILED) {

        perror("Error en mmap");
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);

    }



    memset(shm_ptr, 'A', MEM_SIZE - 1);

    shm_ptr[MEM_SIZE - 1] = '\0';



    printf("Memoria compartida: %s\n", shm_ptr);

    sleep(1);



    for (int i = MEM_SIZE / 2; i < MEM_SIZE - 1; i++) {

        shm_ptr[i] = x;

    }



    printf("Memoria compartida: %s\n", shm_ptr);



    munmap(shm_ptr, MEM_SIZE);

    shm_unlink(SHM_NAME);



    return 0;

}