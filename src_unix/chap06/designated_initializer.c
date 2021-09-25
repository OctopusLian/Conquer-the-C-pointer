#include <stdio.h>

typedef struct {
    int a;
    int b;
    int c;
    int array[10];
} Hoge;

typedef union {
    int int_value;
    double double_value;
} Piyo;

int main(void)
{
    // 对指定的结构体成员进行初始化
    // 对指定的数组下标对应的元素进行初始化
    // 排在其后的数值会继续被分配给指定下标的元素之后的元素
    Hoge hoge = {.b = 3, .c = 5, {[3] = 10, 11, 12}};

    fprintf(stderr, "hoge.b..%d, hoge.c..%d\n", hoge.b, hoge.c);
    fprintf(stderr, "hoge.array[3..] %d, %d, %d\n",
	    hoge.array[3], hoge.array[4], hoge.array[5]);

    // 对指定的联合体成员进行初始化
    Piyo piyo = {.double_value = 123.456};
    fprintf(stderr, "piyo.double_value..%f\n", piyo.double_value);

    return 0;
}
