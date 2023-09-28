#include <stdio.h>

void dfs(int a[][6], int *v, int i)
{
    int j = 0;
    printf("\n--%d--\n", i);
    v[i] = 1;
    for (j = 0; j < 6; j++)
    {
        // printf("<%d,%d>,", i, j);
        if (a[i][j] == 1 && v[j] == 0)
        {
            // printf("\n printing at i is %d j is %d", i, j);
            dfs(a, v, j);
        }
    }
}

int main()
{
    int a[6][6] = {{0, 0, 1, 0, 0, 0},
                   {0, 0, 0, 1, 0, 0}, 
                   {1, 0, 0, 1, 1, 0}, 
                   {0, 1, 1, 0, 1, 1}, 
                   {0, 0, 1, 1, 0, 1}, 
                   {0, 0, 0, 1, 1, 0}};
    int v[6] = {0, 0, 0, 0, 0, 0};
    dfs(a, v, 0);
    return 0;
}