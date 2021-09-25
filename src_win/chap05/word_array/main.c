#include <stdio.h>
#include <stdlib.h>
#include "get_word.h"
#include "word_manage.h"

#define WORD_LEN_MAX (1024)

int main(int argc, char **argv)
{
    char        buf[WORD_LEN_MAX];
    FILE        *fp;

    if (argc == 1) {
        fp = stdin;
    } else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            fprintf(stderr, "%s:%s can not open.\n", argv[0], argv[1]);
	    exit(1);
        }
    }

    /* 初始化单词管理单元 */
    word_initialize();

    /* 一边读入文件，一边添加单词 */
    while (get_word(buf, WORD_LEN_MAX, fp) != EOF) {
        add_word(buf);
    }
    /* 输出单词的出现频率 */
    dump_word(stdout);

    /* 单词管理单元的结束处理 */
    word_finalize();

    return 0;
}
