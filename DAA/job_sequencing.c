#include <stdio.h>

void display(float *, int, char*);
void mysort(float *, float*, float*, int);

void main() {
    float deadlines[5] = {2.0, 2.0, 1.0, 3.0, 4.0};
    float profit[5] = {20.0, 60.0, 40.0, 100.0, 80.0};
    float job[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    
    int max_deadline = 0;
    float cur_profit = 0.0;
    
    int i, j;

    mysort(profit, deadlines, job, 5);
    display(job, 5, "Job");
    display(deadlines, 5, "Deadline");
    display(profit, 5, "Profit");

    printf("\n\nJob\t\tSlot\t\tProfit\n");
    printf("----\t\t----\t\t------\n");

    // Find the maximum deadline to define slot size
    for (i = 0; i < 5; i++) {
        if (max_deadline < deadlines[i])
            max_deadline = (int)deadlines[i];
    }

    int selected[max_deadline + 1]; // Slot array (1-based index)
    for (i = 0; i <= max_deadline; i++) {
        selected[i] = 0; // Initialize all slots as empty
    }

    for (i = 0; i < 5; i++) {
        // Find the latest available slot before or at its deadline
        for (j = (int)deadlines[i]; j > 0; j--) {
            if (selected[j] == 0) { // If the slot is empty
                selected[j] = 1;
                printf("\n%.0f\t\t%d\t\t%.2f", job[i], j, profit[i]);
                cur_profit += profit[i];
                break; // Move to the next job
            }
        }
    }

    printf("\n\nTotal profit: %.2f\n", cur_profit);
}

void mysort(float profit[], float deadlines[], float job[], int n) {
    int i, j;
    float tmp;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                // Swap profit
                tmp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tmp;

                // Swap deadlines
                tmp = deadlines[j];
                deadlines[j] = deadlines[j + 1];
                deadlines[j + 1] = tmp;

                // Swap job numbers
                tmp = job[j];
                job[j] = job[j + 1];
                job[j + 1] = tmp;
            }
        }
    }
}

void display(float A[], int n, char *s) {
    int i;
    printf("\n\n------Sorted %s -----\n\n", s);
    for (i = 0; i < n; i++) {
        printf("%.2f  ", A[i]);
    }
    printf("\n");
}

