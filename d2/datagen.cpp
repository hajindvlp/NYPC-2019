#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n;

    srand(time(0));

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
        {
            if(i == j) printf("0 ");
            else printf("%d ", rand()%100);
        }
        printf("\n");
    }
}