#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *ptr = fopen("abc2.txt","r");
    char ch[200];
    while (fgets(ch,5,ptr) != NULL)
    {
        printf("%s",ch);
    }
    fclose(ptr);
    return 0;
}