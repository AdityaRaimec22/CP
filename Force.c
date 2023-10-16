#include <stdio.h>

int main()
{
    float mass, acceleration, force;

    printf("Enter the mass of the object: ");
    scanf("%f", &mass);

    printf("Enter the acceleration of the object: ");
    scanf("%f", &acceleration);

    force = mass * acceleration;

    printf("\nThe force acting on the object is: %.2f", force);

    return 0;
}
