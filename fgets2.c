#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *ptr = fopen("abc2.txt","r");

    char ch[100];
    while (fgets(ch,3,ptr) !=NULL)
    {
        printf("%s",ch);
    }

    fclose(ptr);
    
    return 0;
}