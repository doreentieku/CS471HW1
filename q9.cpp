#include <iostream>
using namespace std;

int main()
{
    int pid[4] = {1, 2, 3, 4};
    int arrival[4] = {10, 35, 45, 50};
    int burst[4] = {20, 5, 10, 50};
    int completion[4];

    int currentTime = 0;

    for (int i = 0; i < 4; i++)
    {
        if (currentTime < arrival[i])
        {
            currentTime = arrival[i];
        }

        currentTime += burst[i];
        completion[i] = currentTime;
    }

    cout << "ProcessID\tArrival\tCPU Burst\tCompletion\n";
    for (int i = 0; i < 4; i++)
    {
        cout << pid[i] << "\t\t"
             << arrival[i] << "\t"
             << burst[i] << "\t\t"
             << completion[i] << endl;
    }

    return 0;
}