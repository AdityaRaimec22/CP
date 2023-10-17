#include<stdio.h>
int main(){
    int a;
    int b;
    scanf("%d %d",&a,&b);
    int temp = a;
    a = b;
    b = temp;
    printf("The two swapped no's are %d %d\n",a,b);
    printf("The addition of two no's are %d\n",a+b);
    printf("the substraction of the given no's are %d\n",a-b);
    printf("The division of the given no's are %d\n",a/b);
    printf("the multiplication of the given no's are %d\n",a*b);
}