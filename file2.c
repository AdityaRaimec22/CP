#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *fptr = NULL;
    char ch;
    fptr = fopen("abc1.txt","r");
    // fgets(ch,sizeof(ch),fptr);
    ch = fgetc(fptr);
    printf("%c",ch);
    fclose(fptr);
    return 0;
}