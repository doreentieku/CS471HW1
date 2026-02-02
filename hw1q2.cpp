#include <iostream>
#include <unistd.h>     // fork(), getpid(), getppid()
#include <sys/wait.h>   // wait()
#include <cstdlib>      // exit()
#include <cstdio>       // printf, fprintf

int main() {
    int n = 10;   // change to 10 for the second run

    // Fork CHILD 1
    pid_t pid1 = fork();

    if (pid1 < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    if (pid1 == 0) {
        // CHILD 1: sum of natural numbers
        printf("I am CHILD 1. My PID is %d and my parent's PID is %d.\n", getpid(), getppid());

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        
        printf("The sum of the first %d natural numbers is: %d\n", n, sum);
        exit(0); // child 1 stops here
    }

    // Fork CHILD 2
    pid_t pid2 = fork();

    if (pid2 < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    if (pid2 == 0) {
        // CHILD 2: sum of cubes
        printf("I am CHILD 2. My PID is %d and my parent's PID is %d.\n", getpid(), getppid());

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += (i * i * i);
        }

        printf("The sum of the cubes of the first %d natural numbers is: %d\n", n, sum);
        exit(0); // child 2 stops here
    }

    // Parent waits for both children
    wait(NULL);
    wait(NULL);

    return 0;
}
