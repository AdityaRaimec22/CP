#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    // char ch[MAX_LENGTH]; // Changed the size of 'ch' array to MAX_LENGTH

    // fgets(ch, sizeof(ch), stdin); // Replaced 'gets' with 'fgets' to avoid buffer overflow

    // // ch[strcspn(ch, "\n")] = '\0'; // Remove the newline character from the input string

    // int a = strlen(ch);

    // printf("Length of the string: %d\n", a);
    // printf("The string that you entered is: %s\n", ch);


    // int b = 10;
    // int *a = &b;

    // char str[] = "Hello my name is chin chin chu";
    // char *ch = str;

    // char str[500] = "hello how are you";

    char *ch = "hello how are you";

    int a = strlen(ch);

    for (int i = 0; i < a; i++)
    {
        printf("%c",ch[i]);
    }

    return 0;
}   
