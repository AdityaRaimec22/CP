#include<stdio.h>

void circle(int r,float* area, float* prm){
    *area = 3.14*r*r;
    *prm = 2*3.14*r;
}

int main(){
    float a,pr,*area = &a,*prm = &pr;
    circle(10,area,prm);
    printf("%f %f",*area,*prm);
    return 0;
}