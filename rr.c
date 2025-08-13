#include <stdio.h>

void takeInput(int n, int at[], int bt[]);
void shiftQueueItems(int count, int arr[]);
void findTatWt(int n, int at[], int bt[], int ct[], int tat[], int wt[]);
void printTabular(int n, int at[], int bt[], int ct[], int tat[], int wt[]);

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    takeInput(n, at, bt);

    
}

void takeInput(int n, int at[], int bt[]){
    for (int i=0;i<n;i++){
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }
}

void shiftQueueItems(int count, int arr[]){
    for (int i=0;i<count;i++){
        arr[i] = arr[i+1];
    }
}

void findTatWt(int n, int at[], int bt[], int ct[], int tat[], int wt[]){
    for (int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
}

void printTabular(int n, int at[], int bt[], int ct[], int tat[], int wt[]){
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");

    for (int i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }    
}
