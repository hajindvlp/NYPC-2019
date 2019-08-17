#include <stdio.h>
#define LIM 1000000

int count[LIM+1];
unsigned long long int a, b;
int cnt;

int main()
{
    int i, j;

    scanf("%ull %ull", &a, &b);
    for(i=1 ; i<=LIM ; i++)
        for(j=1 ; j<=LIM/i ; j++) 
            count[i*j]++;
    for(i=a ; i<=b ; i++)
    {
        if(i>=LIM) 
        {
            for(j=1 ; j*j<i ; j++) 
                if(i%j == 0 && j<=LIM && i/j<=LIM) 
                {
                    cnt+=count[j]*count[i/j];
                    break;
                }
            if(i == j*j) cnt+=count[j]*2-1;
        }
        else cnt+=count[i];
    }
    printf("%d", cnt);
    return 0;
}