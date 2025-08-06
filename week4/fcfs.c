#include <stdio.h>

// Function to find Completion Time
void findCT(int processes[], int n, int bt[], int at[], int ct[]) {
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (at[i] > ct[i - 1])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }
}

// Function to find Turnaround Time
void findTAT(int processes[], int n, int ct[], int at[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
    }
}

// Function to find Waiting Time
void findWT(int processes[], int n, int tat[], int bt[], int wt[]) {
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
    }
}

// Function to calculate average Turnaround Time
float findAvgTAT(int tat[], int n) {
    int totalTAT = 0;
    for (int i = 0; i < n; i++) {
        totalTAT += tat[i];
    }
    return (float)totalTAT / n;
}

// Function to calculate average Waiting Time
float findAvgWT(int wt[], int n) {
    int totalWT = 0;
    for (int i = 0; i < n; i++) {
        totalWT += wt[i];
    }
    return (float)totalWT / n;
}

// Function to print all metrics
void printAll(int processes[], int n, int at[], int bt[], int ct[], int tat[], int wt[]) {
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processes[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    float avgTAT = findAvgTAT(tat, n);
    float avgWT = findAvgWT(wt, n);

    printf("\nAverage Turnaround Time = %.2f", avgTAT);
    printf("\nAverage Waiting Time = %.2f\n", avgWT);
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], at[n], bt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    findCT(processes, n, bt, at, ct);
    findTAT(processes, n, ct, at, tat);
    findWT(processes, n, tat, bt, wt);
    printAll(processes, n, at, bt, ct, tat, wt);

    return 0;
}
