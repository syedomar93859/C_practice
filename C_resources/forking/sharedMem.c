#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid, NULL, 0);

    pid_t pid = fork();

    if (pid == 0) {
        sleep(1);
        printf("Child read: %s\n", str);
        strcpy(str, "Child was here!");
        printf("Child wrote: %s\n", str);
    } else {
        strcpy(str, "Hello from parent!");
        printf("Parent wrote: %s\n", str);
        wait(NULL);
        printf("Parent sees after child: %s\n", str);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}