#include <stdio.h>
#include <math.h>

unsigned long long int a, b, ac, bc;

int main()
{
    int i;

    scanf("%llu %llu", &a, &b);
    a--;
    for(i=1 ; i<=a ; i++)
        ac+=a/i;
    for(i=1 ; i<=b ; i++)
        bc+=b/i;

    printf("%llu", bc-ac);
}