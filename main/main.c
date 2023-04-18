#include <stdio.h>
#include <utils.h>

int main(void)
{
    int a = 42;
    printf("%d is the same as %d\n", a, identity(a));

    return 0;
}
