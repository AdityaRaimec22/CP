#include <stdio.h>
#define PI 3.14159

int main()
{
    float radius, area, circumference;

    printf("Enter the radius of circle: ");
    scanf("%f", &radius);

    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    printf("\nArea of circle: %.2f", area);
    printf("\nCircumference of circle: %.2f", circumference);

    return 0;
}
