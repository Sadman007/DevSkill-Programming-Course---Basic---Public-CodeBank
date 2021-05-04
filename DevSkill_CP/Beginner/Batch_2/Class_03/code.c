#include <stdio.h>

int main()
{
    /// C style I/O
    /**
        int -> %d
        long long int / long long -> %lld
        float -> %f
        array of characters -> %s
        double -> %lf

        scanf() -> returns the number of variables it accepted
        printf() -> returns the number of characters it printed
    **/
    double radius;
    scanf("%lf", &radius);
    printf("%lf\n", radius);
    return 0;
}

