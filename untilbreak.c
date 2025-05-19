#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int i = 20, pid, stat;
    char strI[1024];

    while (1) {
        sprintf(strI, "%d", i);
        
        pid = fork();
        if (pid == 0) {
            execl("forks", "forks", strI, NULL);
        } else {
            wait(&stat);
            printf("%d forks finished with status %d\n", i, WEXITSTATUS(stat));
            if (WEXITSTATUS(stat) != 0) {
                printf("Error: Child process exited with non-zero status\n");
                exit(1);
            }
        }
        
        i += 20;
    }
}