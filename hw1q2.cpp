#include <iostream>
#include <unistd.h>     // fork()
#include <sys/wait.h>   // wait()
#include <cstdlib>      // exit()

int main() {
    int n = 10;   // n can be 3 or 10

    // CHILD 1: sum of natural numbers
    if (fork() == 0) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum = sum + i;
        }
        std::cout << "The sum of the first " << n
                  << " natural numbers is: " << sum << std::endl;
        exit(0);
    }

    // CHILD 2: sum of cubes
    if (fork() == 0) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum = sum + (i * i * i);
        }
        std::cout << "The sum of the cubes of the first " << n
                  << " natural numbers is: " << sum << std::endl;
        exit(0);
    }

    // Parent waits for both children
    wait(NULL);
    wait(NULL);

    return 0;
}
