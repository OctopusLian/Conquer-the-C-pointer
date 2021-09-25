#include <stdio.h>
#include "word_manage_p.h"

/************************************************************
 * 对单词列表进行转储
 ************************************************************/
void dump_word(FILE *fp)
{
    int         i;

    for (i = 0; i < num_of_word; i++) {
        fprintf(fp, "%-20s%5d\n",
                word_array[i].name, word_array[i].count);
    }
}
