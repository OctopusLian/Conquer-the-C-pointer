#include <stdio.h>

int hoge;

int main(void)
{
    char        buf[256];

    printf("&hoge...%p\n", (void*)&hoge);

    printf("Input initial value.\n");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &hoge);

    for (;;) {
        printf("hoge..%d\n", hoge);
        /*
         * 使用getchar()进入等待输入的状态
         * 每敲击一次回车键，hoge的值都会增加
         */
        getchar();
        hoge++;
    }

    return 0;
}
