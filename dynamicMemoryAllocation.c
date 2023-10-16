#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int *pa = (int *)malloc(n*sizeof(int));
    *pa = 2;
    *(pa+1) = 7;
    *(pa+3) = 22;
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",*(pa+i));
    }
    
    return 0;
}