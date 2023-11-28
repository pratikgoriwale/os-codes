#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Samarth Khorate SE AIDS A2 [22539]\n");
    // ps command simulation
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());

    // fork command simulation
    pid_t childPid = fork();

    if (childPid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (childPid == 0) {
        // Child process
        printf("Child Process ID: %d\n", getpid());

        // exec command simulation
        execlp("ls", "ls", "-l", NULL);

        // If exec fails
        perror("Exec failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        printf("Parent Process waiting for Child Process to complete...\n");

        // wait command simulation
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child Process exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child Process terminated by signal %d\n", WTERMSIG(status));
        }

        // join command simulation
        printf("Parent Process continues execution.\n");
    }

    return 0;
}
