#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLOGAN_MAX_LEN (1024)

void read_slogan(FILE *fp, char **slogan)
{
    char buf[1024];
    int slogan_len;
    int  i;

    for (i = 0; i < 7; i++) {
        fgets(buf, SLOGAN_MAX_LEN, fp);

	slogan_len = strlen(buf);
	if (buf[slogan_len - 1] != '\n') {
	    fprintf(stderr, "标语过长。\n");
	    exit(1);
	}
        /* 删除换行字符 */
        buf[slogan_len - 1] = '\0';

        /* 分配用于保存一条标语的内存空间 */
        slogan[i] = malloc(sizeof(char) * (slogan_len + 1));

        /* 复制标语的内容 */
        strcpy(slogan[i], buf);
    }
}

int main(void)
{
    char *slogan[7];
    int i;

    read_slogan(stdin, slogan);

    /* 显示读取进来的标语 */
    for (i = 0; i < 7; i++) {
        printf("%s\n", slogan[i]);
    }

    return 0;
}
