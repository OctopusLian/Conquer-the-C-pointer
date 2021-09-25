#include <stdio.h>
#include <stdlib.h>

int             global_variable;
static int      file_static_variable;

void func1(void)
{
    int func1_variable;
    static int local_static_variable;

    printf("&func1_variable..%p\n", (void*)&func1_variable);
    printf("&local_static_variable..%p\n", (void*)&local_static_variable);
}

void func2(void)
{
    int func2_variable;

    printf("&func2_variable..%p\n", (void*)&func2_variable);
}

int main(void)
{
    int *p;

    /* 输出指向函数的指针 */
    printf("func1..%p\n", (void*)func1);
    printf("func2..%p\n", (void*)func2);
    
    /* 输出字符串字面量的地址 */
    printf("string literal..%p\n", (void*)"abc");

    /* 输出全局变量的地址 */
    printf("&global_variable..%p\n", (void*)&global_variable);

    /* 输出文件内static变量的地址 */
    printf("&file_static_variable..%p\n", (void*)&file_static_variable);

    /* 输出局部变量 */
    func1();
    func2();

    /* 通过malloc动态分配的内存的地址 */
    p = malloc(sizeof(int));
    printf("malloc address..%p\n", (void*)p);

    return 0;
}
