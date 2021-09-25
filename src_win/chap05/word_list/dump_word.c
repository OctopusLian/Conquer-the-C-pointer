#include <stdio.h>
#include "word_manage_p.h"

/************************************************************
 * 对单词列表进行转储
 ************************************************************/
void dump_word(FILE *fp)
{
    Word        *pos;

    for (pos = word_header; pos; pos = pos->next) {
        fprintf(fp, "%-20s%5d\n",
                pos->name, pos->count);
    }
}
