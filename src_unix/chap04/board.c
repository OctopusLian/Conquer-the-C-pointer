#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size;

    printf("board size?");
    scanf("%d", &size);

    /* 分配size × size的二维数组 */
    int (*board)[size] = malloc(sizeof(int) * size * size);

    /* 对二维数组赋予适当的值 */
    for (int i = 0; i < size; i++) {
	for (int j = 0; j < size; j++) {
	    board[i][j] = i * size + j;
	}
    }

    /* 显示所赋的值 */
    for (int i = 0; i < size; i++) {
	for (int j = 0; j < size; j++) {
	    printf("%2d, ", board[i][j]);
	}
	printf("\n");
    }
}
