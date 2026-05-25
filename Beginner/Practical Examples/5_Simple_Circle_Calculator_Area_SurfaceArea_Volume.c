#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    const double PI = 3.14159;

    double radius = 0.0;
    printf("Enter the radius (in feet): ");
    scanf("%lf", &radius);

    double area = 0.0;
    area = PI * pow(radius, 2);
    printf("\n\nThe area of the circle is: %.2lf feet.", area);

    double surface_area = 0.0;
    surface_area = 4 * PI * pow(radius, 2);
    printf("\nSurface Area: %.2lf feet.", surface_area);

    double volume = 0.0;
    volume = (4.0 / 3.0) * PI * pow(radius, 3);
    printf("\nVolume: %.2lf feet.", volume);

    return 0;
}
