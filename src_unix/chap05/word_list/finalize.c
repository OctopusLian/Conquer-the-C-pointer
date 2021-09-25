#include <stdlib.h>
#include "word_manage_p.h"

/************************************************************
 * 执行单词管理单元的结束处理
 ************************************************************/
void word_finalize(void)
{
    Word        *temp;

    /* 通过free()释放所有已添加的单词 */
    while (word_header != NULL) {
        temp = word_header;
        word_header = word_header->next;

        free(temp->name);
        free(temp);
    }
}
