#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Edge
{
    int source;
    int destination;
    int weight;
};
struct Graph
{
    int V;
    int E;
    struct Edge *edge;
};
struct Graph *createGraph(int V, int E)
{
    struct Graph *g;
    g = (struct Graph *)malloc(sizeof(struct Graph));
    g->V = V;
    g->E = E;
    g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));
    return g;
}
void displaySolution(int dist[], int n, int flag)
{
    int i;
    if (flag)
    {
        printf("\nVertex\tDistance from Source Vertex\n");
        for (i = 0; i < n; ++i)

            printf("%d \t\t %d\n", i, dist[i]);
        printf("This graph contains no negative edge cycle\n");
    }
    else
        printf("This graph contains negative edge cycle\n");
}
void BellmanFord(struct Graph *g, int source)
{
    int i, j, u, v, w, flag = 1;
    int V = g->V;

    int E = g->E;
    int StoreDistance[V];
    for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;
    StoreDistance[source] = 0;
    for (i = 1; i <= V - 1; i++)
    {
        for (j = 0; j < E; j++)
        {
            u = g->edge[j].source;
            v = g->edge[j].destination;
            w = g->edge[j].weight;
            if (StoreDistance[u] + w < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + w;
        }
    }
    for (i = 0; i < E; i++)
    {
        u = g->edge[i].source;
        v = g->edge[i].destination;
        w = g->edge[i].weight;
        if (StoreDistance[u] + w < StoreDistance[v])
            flag = 0;
    }
    displaySolution(StoreDistance, V, flag);
}
int main()
{
    int V, E, S, i;
    printf("Enter number of vertices in a graph\n");
    scanf("%d", &V);
    printf("Enter number of edges in a graph\n");
    scanf("%d", &E);
    printf("Enter your source vertex number\n");
    scanf("%d", &S);
    struct Graph *gp = createGraph(V, E);
    for (i = 0; i < E; i++)

    {
printf("\nEnter edge %d properties Source, destination, weight respectively\n",i+1);
scanf("%d",&gp->edge[i].source);
scanf("%d",&gp->edge[i].destination);
scanf("%d",&gp->edge[i].weight);
    }
    BellmanFord(gp, S);

    return 0;
}