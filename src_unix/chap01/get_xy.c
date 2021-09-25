#include <stdio.h>

void get_xy(double *x_p, double *y_p)
{
    /* 输出形参x_p和y_p的值及地址 */
    printf("x_p..%p, y_p..%p\n", (void*)x_p, (void*)y_p);
    printf("&x_p..%p, &y_p..%p\n", (void*)&x_p, (void*)&y_p);

    /* 将值保存到以参数传递进来的地址中 */
    *x_p = 1.0;
    *y_p = 2.0;
}

int main(void)
{
    double x;
    double y;

    /* 输出变量x和y的地址 */
    printf("&x..%p, &y..%p\n", (void*)&x, (void*)&y);

    /*
     * 将变量x和y的地址作为参数传递
     * get_xy()将值保存到这两个地址里
     */
    get_xy(&x, &y);

    /* 输出接收的值 */
    printf("x..%f, y..%f\n", x, y);

    return 0;
}
