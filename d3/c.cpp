#include <stdio.h> 
#include <string.h> 
  
char text[2000005];


void pro() 
{ 
    int n = strlen(text); 
    int on = n;
    int i; 
    int cnt = 0;

    for(i=0 ; i<n-1 ; i++)
        text[i+n] = text[i];

    n = 2*n - 1;
    n = 2*n + 1; 
    int l[n]; 
    l[0] = 0; 
    l[1] = 1; 
    int c = 1;  
    int r = 2; 
    int ir; 
    int expand = -1; 
    int diff = -1; 
    int mxl = 0; 
    int mxlc = 0; 
    int s = -1; 
    int e = -1; 

    for (i = 2; i < n; i++)  
    { 
        ir  = 2*c-i; 
        expand = 0; 
        diff = r - i; 
        if(diff > 0)  
        { 
            if(l[ir] < diff) 
                l[i] = l[ir]; 
            else if(l[ir] == diff && i == n-1) 
                l[i] = l[ir]; 
            else if(l[ir] == diff && i < n-1)  
            { 
                    l[i] = l[ir]; 
                    expand = 1; 
            } 
            else if(l[ir] > diff)  
            { 
                l[i] = diff; 
                expand = 1;  
            } 
        } 
        else
        { 
            l[i] = 0; 
            expand = 1; 
        } 
          
        if (expand == 1) 
        { 
            while (((i + l[i]) < n && (i - l[i]) > 0) &&  
                ( ((i + l[i] + 1) % 2 == 0) ||  
                (text[(i + l[i] + 1)/2] == text[(i-l[i]-1)/2] ))) 
            { 
                l[i]++; 
            } 
        } 
  
        if(l[i] > mxl)  
        { 
            mxl = l[i]; 
            mxlc = i; 
        } 

        if (i + l[i] > r)  
        { 
            c = i; 
            r = i + l[i]; 
        } 
    }
    for(i=0 ; i<n ; i++)
        if(l[i] >= on && l[i]%2 == on%2)
            cnt++;
    printf("%d", cnt);
} 
  
int main() 
{
    scanf("%s", &text);
    pro();  
    return 0; 
} 