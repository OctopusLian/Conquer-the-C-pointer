#include <stdio.h>

int main(void)
{
    int array[5];
    int *p;
    int i;

    /* 对数组array设置值 */
    for (i = 0; i < 5; i++) {
        array[i] = i;
    }

	/* 输出其内容(指针版) */
    for (p = &array[0]; p != &array[5]; p++) {
        printf("%d\n", *p);
    }

    return 0;
}
