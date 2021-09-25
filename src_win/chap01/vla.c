#include <stdio.h>

int main(void)
{
    int size1, size2, size3;

    printf("请输入3个整数值\n");
    scanf("%d%d%d", &size1, &size2, &size3);

    // 可变长数组的声明
    int array1[size1];
    int array2[size2][size3];

    // 对可变长数组进行适当的赋值
    int i;
    for (i = 0; i < size1; i++) {
	array1[i] = i;
    }
    int j;
    for (i = 0; i < size2; i++) {
	for (j = 0; j < size3; j++) {
	    array2[i][j] = i * size3 + j;
	}
    }

    // 输出所赋的值
    for (i = 0; i < size1; i++) {
	printf("array1[%d]..%d\n", i, array1[i]);
    }
    for (i = 0; i < size2; i++) {
	for (j = 0; j < size3; j++) {
	    printf("\t%d", array2[i][j]);
	}
	printf("\n");
    }
    printf("sizeof(array1)..%zd\n", sizeof(array1));
    printf("sizeof(array2)..%zd\n", sizeof(array2));
}
