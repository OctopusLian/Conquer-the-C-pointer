#include <stdio.h>

int main(void)
{
    int array[5];
    int i;

    /* 对数组array设置值 */
    for (i = 0; i < 5; i++) {
        array[i] = i;
    }

    /* 输出其内容 */
    for (i = 0; i < 5; i++) {
        printf("%d\n", array[i]);
    }

    /* 输出array中各元素的地址 */
    for (i = 0; i < 5; i++) {
        printf("&array[%d]... %p\n", i, (void*)&array[i]);
    }

    return 0;
}
