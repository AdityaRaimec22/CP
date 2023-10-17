#include<stdio.h>

int main() {
    int a[3][3] = {
        {1,2,3},
        {4,5,6}
    };
    int *ptr = a[0];
    printf("%p\n",ptr);
    printf("%p",&a);

    return 0;
}

