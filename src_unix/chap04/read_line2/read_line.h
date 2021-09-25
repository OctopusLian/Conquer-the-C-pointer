#ifndef READ_LINE_H_INCLUDED
#define READ_LINE_H_INCLUDED

#include <stdio.h>

typedef enum {
    READ_LINE_SUCCESS,      /* 正常地读取了1行 */
    READ_LINE_EOF,          /* 读到了文件末尾 */
    READ_LINE_OUT_OF_MEMORY /* 因内存不足而失败 */
} ReadLineStatus;

ReadLineStatus read_line(FILE *fp, char **line);
void free_buffer(void);

#endif /* READ_LINE_H_INCLUDED */
