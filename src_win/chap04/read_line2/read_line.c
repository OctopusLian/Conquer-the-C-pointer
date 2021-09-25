#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "read_line.h"

#define ALLOC_SIZE      (256)

/*
 * 用于读取行的缓冲区。可根据需要进行扩展，不会缩小
 * 通过调用free_buffer()释放缓冲区
 */
static char *st_line_buffer = NULL;

/*
 * 给st_line_buffer指向的区域分配的内存空间的大小
 */
static int  st_current_buffer_size = 0;

/*
 * st_line_buffer中当前保存的字符的大小。
 */
static int  st_current_used_size = 0;

/*
 * 向st_line_buffer的末尾添加1个字符
 * 可根据需要对st_line_buffer指向的内存空间进行扩展
 */
static ReadLineStatus
add_character(int ch)
{
    /*
     * 由于st_current_used_size一定是每次增加1字节
     * 所以应该不会出现因以下断言而突然跳出本函数的情况
     */
    assert(st_current_buffer_size >= st_current_used_size);

    /*
     * 当st_current_used_size等于st_current_buffer_size时
     * 对缓冲区进行扩展
     */
    if (st_current_buffer_size == st_current_used_size) {
        char *temp;
        temp = realloc(st_line_buffer,
                       (st_current_buffer_size + ALLOC_SIZE)
                       * sizeof(char));
        if (temp == NULL) {
            return READ_LINE_OUT_OF_MEMORY;
        }
        st_line_buffer = temp;
        st_current_buffer_size += ALLOC_SIZE;
    }
    /* 在缓冲区末尾添加1个字符 */
    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size++;

    return READ_LINE_SUCCESS;
}

/*
 * 释放缓冲区。虽然不调用本函数其实也没什么区别
 * 但如果你想要在程序结束时把通过malloc()分配的内存空间全部free()掉
 * 那么在最后调用本函数即可
 */
void free_buffer(void)
{
    free(st_line_buffer);
    st_line_buffer = NULL;
    st_current_buffer_size = 0;
    st_current_used_size = 0;
}

/*
 * 从fp读取1行
 */
ReadLineStatus read_line(FILE *fp, char **line)
{
    int                 ch;
    ReadLineStatus      status = READ_LINE_SUCCESS;

    st_current_used_size = 0;
    while ((ch = getc(fp)) != EOF) {
        if (ch == '\n') {
            status = add_character('\0');
            if (status != READ_LINE_SUCCESS)
                goto FUNC_END;
            break;
        }
        status = add_character(ch);
        if (status != READ_LINE_SUCCESS)
            goto FUNC_END;
    }
    if (ch == EOF) {
        if (st_current_used_size > 0) {
            /* 最后一行的后面没有换行的情况 */
            status =add_character('\0');
            if (status != READ_LINE_SUCCESS)
                goto FUNC_END;
        } else {
            status = READ_LINE_EOF;
            goto FUNC_END;
        }
    }

    *line = malloc(sizeof(char) * st_current_used_size);
    if (*line == NULL) {
        status = READ_LINE_OUT_OF_MEMORY;
        goto FUNC_END;
    }
    strcpy(*line, st_line_buffer);

  FUNC_END:
    if (status != READ_LINE_SUCCESS && status != READ_LINE_EOF) {
        free_buffer();
    }
    return status;
}
