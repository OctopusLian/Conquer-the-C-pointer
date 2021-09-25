#include <stdio.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
    // 宽字符串字面量
    wchar_t str[] = L"日本語123𠮟";

    // 显示wchar_t的长度
    printf("sizeof(wchar_t)..%d\n", (int)sizeof(wchar_t));
    // 显示数组str的长度
    printf("str length..%d\n", (int)(sizeof(str) / sizeof(str[0])));
    
    // 输出str的内容
    for (int i = 0; i < (sizeof(str) / sizeof(str[0])); i++) {
	printf("str[%d]..%0x\n", i, str[i]);
    }

    return 0;
}
