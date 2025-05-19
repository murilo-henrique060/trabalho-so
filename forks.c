#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int n, pid;

    sscanf(argv[1], "%d", &n);

    for (int i = 0; i < n; i++) {
        pid = fork();
        
        if (pid < 0) {
            while (wait(NULL) > 0);

            printf("Fork failed on: %d\n", i);
            exit(1);
        } else if (pid == 0) {
            execl("helloworld", "helloworld", NULL);
        }
    }
}