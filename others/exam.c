#include<stdio.h>
#include<string.h>

int main()
{
    int a[] = {1,2,3,4,5,6},*p;

    p = &a[4];

    printf("%d\n",p[-7]);
    
    return 0;
}