#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *ptr = fopen("abc2.txt","w");

    char ch[200];

    fgets(ch,sizeof(ch),stdin);

    fputs(ch,ptr);


    fclose(ptr);
}