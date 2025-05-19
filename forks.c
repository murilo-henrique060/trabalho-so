#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int i = 0, pid;

    while (pid > 0) {
        pid = fork();
        
        if (pid == 0) {
            execl("helloworld", "helloworld", NULL);
        }

        i++;
    }

    while (wait(NULL) > 0);
    
    printf("Number of forks: %d\n", i);
    exit(0);
}