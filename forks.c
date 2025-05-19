#include <stdio.h>
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

    printf("Number of forks: %d\n", i);
}