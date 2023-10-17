// #include <stdio.h>

// int main() {
//     // Declare an array to store 15 float numbers
//     float numbers[15];
//     float sum = 0;

//     // Take input from the user for 15 float numbers
//     printf("Enter 15 float numbers:\n");
//     for (int i = 0; i < 15; i++) {
//         printf("Enter number %d: ", i + 1);
//         scanf("%f", &numbers[i]);
//     }

//     // Display the numbers in reverse order
//     printf("\nNumbers in reverse order:\n");
//     for (int i = 14; i >= 0; i--) {
//         printf("%.2f\n", numbers[i]);
//     }

//     for(int i=0;i<15;i++){
//         sum+=numbers[i];
//     }
//     printf("The sum of the elements in the array is %f: ",sum);

//     return 0;
// }

#include<stdio.h>
int main(){
    int a;
    int b;
    scanf("%d %d",&a,&b);
    int temp = a;
    a = b;
    b = temp;
    printf("%d %d",a,b);
}
