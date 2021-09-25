#include <stdlib.h>
#include "word_manage_p.h"

/************************************************************
 * 执行单词管理单元的结束处理
 ************************************************************/
void word_finalize(void)
{
    int i;

    /* 释放单词所占用的内存空间 */
    for (i = 0; i < num_of_word; i++) {
        free(word_array[i].name);
    }

    num_of_word = 0;
}
