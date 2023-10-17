#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp = NULL;
    char ch[100];
    
    fp = fopen("abc.txt", "w");

    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    // Use fgets() instead of gets() to read the input
    fgets(ch, sizeof(ch), stdin);

    for (int i = 0; i < strlen(ch); i++)
    {
        fputc(ch[i], fp);
    }
    
    fclose(fp);

    return 0;
}
