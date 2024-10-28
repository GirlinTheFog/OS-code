#include <stdio.h>

int main() {
    int p[20], bt[20], wt[20] = {0}, tat[20], n, i, j, temp;
    float wtavg = 0, tatavg = 0;

    // Input: Number of processes and their burst times
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Burst Time for Process %d: ", p[i]);
        scanf("%d", &bt[i]);
    }

    // Sort processes by burst time (SJF Non-preemptive)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // Swap burst time and process IDs
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    // Calculate waiting time, turnaround time, and their averages
    for (i = 0; i < n; i++) {
        if (i > 0) wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Output: Process details and average times
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) 
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}
