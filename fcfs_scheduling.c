#include <stdio.h>
#include <conio.h>

void main() {
    int numProcesses, arrivalTimes[10], burstTimes[10], turnaroundTimes[10], waitingTimes[10], ganttChart[10], i;
    float averageTurnaroundTime = 0, averageWaitingTime = 0;
    
    for (i = 0; i < 10; i++) {
        arrivalTimes[i] = 0;
        burstTimes[i] = 0;
        waitingTimes[i] = 0;
        ganttChart[i] = 0;
    }
    
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    
    printf("Enter the burst times: ");
    for (i = 0; i < numProcesses; i++) {
        scanf("%d", &burstTimes[i]);
    }
    
    printf("\nEnter the arrival times: ");
    for (i = 0; i < numProcesses; i++) {
        scanf("%d", &arrivalTimes[i]);
    }
    
    ganttChart[0] = 0;
    for (i = 0; i < 10; i++) {
        ganttChart[i + 1] = ganttChart[i] + burstTimes[i];
    }
    
    for (i = 0; i < numProcesses; i++) {
        waitingTimes[i] = ganttChart[i] - arrivalTimes[i];
        turnaroundTimes[i] = ganttChart[i + 1] - arrivalTimes[i];
        averageWaitingTime += waitingTimes[i];
        averageTurnaroundTime += turnaroundTimes[i];
    }
    
    averageWaitingTime /= numProcesses;
    averageTurnaroundTime /= numProcesses;
    
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < numProcesses; i++) {
        printf("\tP%d\t\t%d\t\t%d\n", i, waitingTimes[i], turnaroundTimes[i]);
    }
    
    printf("The average waiting time is %f\n", averageWaitingTime);
    printf("The average turnaround time is %f\n", averageTurnaroundTime);
    
    getch();
}
