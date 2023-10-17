#include<stdio.h>

int main(){
    int a[3][3] = {1,2,3,4,5,6,7,8,9};
    int *p = a[0];
    printf("%p\n",a);
    printf("%p\n",&a[0][0]);
    printf("%p\n",&a);
    printf("%p\n",*a);
    printf("%p\n",a[0]);
    printf("%d\n",*(*(a+1)+2));
    printf("%p",**p);
    
    return 0;
}