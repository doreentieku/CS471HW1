#include <iostream>
#include <thread>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num)
{
    if (num < 2)
        return false;

    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Function that runs in a separate thread
void printPrimes(int limit)
{
    cout << "Prime numbers less than or equal to " << limit << ":\n";

    for (int i = 2; i <= limit; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;

    // Ask the user for input
    cout << "Enter a positive number: ";
    cin >> n;

    // Basic input validation
    if (n < 2)
    {
        cout << "There are no prime numbers less than 2.\n";
        return 0;
    }

    // Create a thread to print prime numbers
    thread primeThread(printPrimes, n);

    // Wait for the thread to finish
    primeThread.join();

    return 0;
}