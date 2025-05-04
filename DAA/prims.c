#include <stdio.h>
#include <conio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[1] = 1; // Start from node 1

    printf("\nThe edges of the Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        visited[b] = 1;
        printf("%d edge (%d, %d) = %d\n", ne++, a, b, min);
        mincost += min;
        cost[a][b] = cost[b][a] = 999; // Mark edge as used
    }

    printf("\nMinimum cost = %d\n", mincost);
    getch();
    return 0;
}
