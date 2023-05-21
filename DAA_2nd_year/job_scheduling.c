#include <stdio.h>
#define MAX 100
typedef struct Job
{
    char id[5];
    int deadline;
    int profit;
} Job;
void displayJobSequence(Job jobs[], int dmax, int timeslot[], int maxprofit)
{
    int i, j;
    // required jobs
    printf("\nRequired Jobs: ");

    for (i = 1; i <= dmax; i++)
    {

        printf("%s", jobs[timeslot[i]].id);
        if (i < dmax)

        {

            printf(" -->");
        }
    }
    printf("\nMax Profit: %d\n", maxprofit);
}
int minValue(int x, int y)
{
    if (x < y)
        return x;
    return y;
}
void sort(Job jobs[], int n)
{
    int i, j;
    Job temp;
    // sort the jobs profit wise in descending order
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (jobs[j + 1].profit > jobs[j].profit)
            {
                temp = jobs[j + 1];
                jobs[j + 1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
    printf("Sorted jobs\n");
    printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for (i = 0; i < n; i++)
    {
        printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
}
void jobSequencingWithDeadline(Job jobs[], int n)
{
    // variables
    int i, j, k, maxprofit = 0;
    // free time slots
    int timeslot[MAX];
    // filled time slots
    int filledTimeSlot = 0;
    // find max deadline value
    int dmax = 0;
    sort(jobs, n);          // sort the jobs profit wise in descending order
    for (i = 0; i < n; i++) // find the maximum deadline
    {

        if (jobs[i].deadline > dmax)
        {
            dmax = jobs[i].deadline;
        }
    }
    // free time slots initially set to -1 [-1 denotes EMPTY]
    for (i = 1; i <= dmax; i++)
    {
        timeslot[i] = -1;
    }

    printf("deadline max: %d\n", dmax);
    for (i = 1; i <= n; i++)
    {

        k = minValue(dmax, jobs[i - 1].deadline);
        while (k >= 1)

        {

            if (timeslot[k] == -1)
            {
                timeslot[k] = i - 1;
                filledTimeSlot++;
                break;
            }
            k--;
        } // endwhile
        // if all time slots are filled then stop
        if (filledTimeSlot == dmax)
        {
            break;
        }
    } // endfor
    // required profit
    for (i = 1; i <= dmax; i++)
    {

        maxprofit += jobs[timeslot[i]].profit;
    }
    displayJobSequence(jobs, dmax, timeslot, maxprofit);
}
int main(void)
{
    // variables
    int i, j, n;
    Job jobs[MAX];
    printf("\n Enter the number of jobs\n");
    scanf("%d", &n);
    printf("\nEnter the job id with deadline and profit\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }
    jobSequencingWithDeadline(jobs, n);
    return 0;
}