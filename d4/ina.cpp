#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int n = 10, i;
    srand(time(0));

    scanf("%d", &n);
    printf("%d\n", n);
    for(i=1 ; i<=n ; i++)
        printf("%d %d\n", rand()%100, rand()%100);
}