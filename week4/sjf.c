#include <stdio.h>
#include <stdbool.h>

void findCT_SJF(int processes[], int n, int bt[], int at[], int ct[]) {
    bool completed[n];
    int time = 0, done = 0;

    for (int i = 0; i < n; i++) completed[i] = false;

    while (done < n) {
        int idx = -1;
        int minBT = 1e9;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time && bt[i] < minBT) {
                minBT = bt[i];
                idx = i;
            }
        }

        if (idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            completed[idx] = true;
            done++;
        } else {
            time++; // CPU idle time
        }
    }
}

void findTAT(int n, int ct[], int at[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
    }
}

void findWT(int n, int tat[], int bt[], int wt[]) {
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
    }
}

float findAvgTAT(int tat[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += tat[i];
    return (float)total / n;
}

float findAvgWT(int wt[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += wt[i];
    return (float)total / n;
}

void printAll(int processes[], int n, int at[], int bt[], int ct[], int tat[], int wt[]) {
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processes[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Turnaround Time = %.2f", findAvgTAT(tat, n));
    printf("\nAverage Waiting Time = %.2f\n", findAvgWT(wt, n));
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], at[n], bt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter Arrival Time for Process P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for Process P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    findCT_SJF(processes, n, bt, at, ct);
    findTAT(n, ct, at, tat);
    findWT(n, tat, bt, wt);
    printAll(processes, n, at, bt, ct, tat, wt);

    return 0;
}
