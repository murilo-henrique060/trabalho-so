#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int n, pid, stat;
    char strI[1024];

    sscanf(argv[1], "%d", &n);

    for (int i = 0; i < n; i++) {
        pid = fork();

        sprintf(strI, "%d", i);
        
        // if (pid < 0) {
        //     perror("fork");
        //     exit(1);
        // } else 
        if (pid == 0) {
            execl("helloworld", "helloworld", argv[1], strI, NULL);
        }
    }

    for (int i = 0; i < n; i++) {
        wait(&stat);
        if (WEXITSTATUS(stat) != 0) exit(1);
    }
}