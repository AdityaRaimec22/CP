#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

    FILE *ptr = fopen("b.txt","w");
    FILE *ptr1 = fopen("c.txt","r");

    // char ch[100];

    // char str;

    // while ((str = fgetc(ptr)) != EOF)
    // {
    //     printf("%c",str);
    // }
    // char *str = fgets(ch,sizeof(ch),ptr);

    // while (str !=NULL)
    // {
    //     printf("%s",ch);
    // }

    // char str[100];

    // printf("its a humble request kindly print the string: ");
    // gets(str);

    // fputs(str,ptr);
    
    // fclose(ptr);

    int num1,num2;

    fscanf(ptr1,"%d %d",&num1,&num2);
    fprintf(ptr,"%d %d",num1,num2);

    return 0;
}