#include <stdio.h>

int main(void)
{
    printf("_Bool..%d\n", (int)sizeof(_Bool)); // C99以后支持
    printf("char..%d\n", (int)sizeof(char));
    printf("short..%d\n", (int)sizeof(short));
    printf("int..%d\n", (int)sizeof(int));
    printf("long..%d\n", (int)sizeof(long));
    printf("long long ..%d\n", (int)sizeof(long long)); // C99以后支持
    printf("float ..%d\n", (int)sizeof(float));
    printf("double ..%d\n", (int)sizeof(double));
}
