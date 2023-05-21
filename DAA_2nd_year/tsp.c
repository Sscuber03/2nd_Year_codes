#include <stdio.h>
int c_matrix[25][25], v_cities[20], no_city, cost = 0;
int least_tsp(int c)
{
    int i, nearest_city = 999;
    int minimum = 999, kmin;
    for (i = 0; i < no_city; i++)
    {
        if ((c_matrix[c][i] != 0) && (v_cities[i] == 0) && (((c_matrix[c][i] < minimum) && (c_matrix[i][c] != c_matrix[c][i])) || ((c_matrix[i][c] == c_matrix[c][i]) && (c_matrix[i][c] + c_matrix[c][i] < minimum))))
        {
            minimum = c_matrix[i][0] + c_matrix[c][i];
            kmin = c_matrix[c][i];
            nearest_city = i;
        }
    }
    if (minimum != 999)
        cost += kmin;
    return nearest_city;
}
void tsp_mincost(int city)
{
    int nearest_city;
    v_cities[city] = 1;
    printf("%d --->", city + 1);
    nearest_city = least_tsp(city);
    if (nearest_city == 999)
    {
        nearest_city = 0;
        printf(" %d", nearest_city + 1);
        cost += c_matrix[city][nearest_city];
        return;
    }
    tsp_mincost(nearest_city);
}
int main()
{
    int i, j;
    printf("\nEnter total no. of cities:");
    scanf("%d", &no_city);
    printf("\nEnter cost matrix:\n");
    for (i = 0; i < no_city; i++)
    {
        printf("\nEnter %d elements in row [%d]\n", no_city, i + 1);
        for (j = 0; j < no_city; j++)
        {
            scanf("%d", &c_matrix[i][j]);
        }
        v_cities[i] = 0;
    }
    printf("\n The cost list is: \n");
    for(i = 0;i<no_city;i++)
    {
        printf("\n");
        for(j = 0;j<no_city;j++)
            printf("\t %d", c_matrix[i][j]);
    }
    printf("\n The path is: \n");
    tsp_mincost(0);
    printf("\n Minimum Cost: ");
    printf("%d \n", cost);
    return 0;
}