#include <stdio.h>

void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("Binary: 0");
        return;
    }

    int binary[32]; // Array to store binary digits
    int index = 0;

    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }

    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}
