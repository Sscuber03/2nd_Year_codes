#include <stdio.h>
#include <limits.h>
int parent[20] = {0}, mincost = 0;
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
void kruskalMST(int n, int mcost[20][20])
{
    int i, j, min, a, b, u, v, ne = 1;
    printf("\n\nThe edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1, min = INT_MAX; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (mcost[i][j] < min)
                {
                    min = mcost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        mcost[a][b] = mcost[b][a] = INT_MAX;
    }
}
void display(int n, int temp[20][20])
{
    int i, j;
    printf("\nInput cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        printf("\n");
        for (j = 1; j <= n; j++)
        {
            if (temp[i][j] == INT_MAX)

                printf("  0");
            else

                printf("%3d", temp[i][j]);
        }
    }
    printf("\n\tMinimum cost = %d\n", mincost);
}
int main()
{
    int n, i, j, cost[20][20], temp[20][20];
    printf("\n\tImplementation of Kruskal's algorithm\n");
    printf("\nEnter the no. of vertices:");
    scanf("%d", &n);
    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            temp[i][j] = cost[i][j];
    kruskalMST(n, cost);
    display(n, temp);
    return 0;
}