#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_manage_p.h"

/*
 * 将位于index后方的元素(包括index)逐一后移
 */
static void shift_array(int index)
{
    int src;    /* 复制源的索引 */

    for (src = num_of_word - 1; src >= index; src--) {
        word_array[src+1] = word_array[src];
    }
    num_of_word++;
}

/*
 * 复制字符串
 * 在某些运行环境中会存在strdup()函数
 * 但标准中没有strdup()函数，因此这里需要自制
 */
static char *my_strdup(char *src)
{
    char        *dest;

    dest = malloc(sizeof(char) * (strlen(src) + 1));
    strcpy(dest, src);

    return dest;
}

/************************************************************
 * 添加单词
 ************************************************************/
void add_word(char *word)
{
    int i;
    int result;

    if (num_of_word >= WORD_NUM_MAX) {
	/* 如果单词的数量超过了数组的元素个数，就执行异常终止 */
	fprintf(stderr, "too many words.\n");
	exit(1);
    }
    for (i = 0; i < num_of_word; i++) {
        result = strcmp(word_array[i].name, word);
        if (result >= 0)
            break;
    }
    if (num_of_word != 0 && result == 0) {
        /* 发现了相同的单词 */
        word_array[i].count++;
    } else {
        shift_array(i);
        word_array[i].name = my_strdup(word);
        word_array[i].count = 1;
    }
}
