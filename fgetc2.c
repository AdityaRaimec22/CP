#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *ptr = fopen("abc2.txt","r");

    char ch;

    while ((ch = fgetc(ptr)) != EOF)
    {
        printf("%c",ch);
    }

    fclose(ptr);
    
}