#include<stdio.h>

void BInary(int decimal){
    int binary[32];
    int index = 0;

    while(decimal > 0){
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }

    for (int i = index - 1; i >= 0; i++)
    {
        printf("%d",binary[i]);
    }
}
    
    int main(){
        int num;
        scanf("%d",&num);
        BInary(num);
    }
