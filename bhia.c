#include <stdio.h>

int main() {
    // int a;
    // scanf("%d",&a);
    // for(int i=1;i<=a;i++)
    // {
    //     for(int j=1;j<=a;j++)
    //     {
    //         scanf("%d",&a);
    //         printf("%d ",a);
    //     }
    //     printf("\n");
    // }
    // for(int i)
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
