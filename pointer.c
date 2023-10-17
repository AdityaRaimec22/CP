#include<stdio.h>
#include<stdlib.h>

int strlen(char ch[] )
{
    int j = 0;
    while (ch[j] != '\0')
    {
        ++j;
    }
    return j;
}

int main () {
    int a[10] = {1,2,3,4,5};

    int *ip = a;

    *(ip + 5) = 10;

    printf("%d\n",*ip);
    printf("%d\n",strlen(a));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    

    return 0;
}