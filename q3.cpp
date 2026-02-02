#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

// The array of 20 elements given in the assignment
int arr[20] = {20, 18, 16, 14,
               12, 10, 8, 6,
               4, 2, -20, -18,
               -16, -14, -12, -10,
               -8, -6, -4, -2};

// Each thread will store its sum here (one slot per thread)
int partial[NUM_THREADS];

/*
  Thread function:
  - Each thread gets an id (0..4)
  - It sums 4 numbers from the array
  - It stores that sum into partial[tid]
*/
void *PrintHello(void *threadid)
{
    long tid = (long)threadid; // thread id: 0,1,2,3,4
    int start = tid * 4;       // starting index: 0,4,8,12,16
    int sum = 0;

    // Add 4 elements for this thread
    for (int i = start; i < start + 4; i++)
    {
        sum += arr[i];
    }

    // Save the result so main can add everything later
    partial[tid] = sum;

    // Print what this thread did
    printf("Thread %ld adds elements [%d..%d] sum = %d\n",
           tid + 1, start, start + 3, sum);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // 1) Create 5 threads
    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("Creating thread %ld\n", t + 1);

        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }

    // 2) Wait for all threads to finish
    for (t = 0; t < NUM_THREADS; t++)
    {
        pthread_join(threads[t], NULL);
    }

    // 3) After all threads are done, main adds all partial sums
    int total = 0;
    for (int i = 0; i < NUM_THREADS; i++)
    {
        total += partial[i];
    }

    // 4) Print the final sum of all 20 elements
    printf("Final sum of all 20 elements = %d\n", total);

    return 0;
}
