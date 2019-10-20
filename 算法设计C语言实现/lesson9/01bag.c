#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b) ? (a):(b))

/**
 * 物品结构体
 */
typedef struct{
    int* vol;   // 物品的体积
    int* value; // 价值
    int num;    // 物品的个数
}article;

/**
 * 01背包问题，自底向上的思路 
 * @param a 物品结构体
 * @param size 背包的大小
 * @return 
 */
int bag(article* a, int size) {
    int v[a->num+1][size+1];
    for (int i = 0; i <= a->num; ++i) {
        for (int j = 0; j <= size; ++j) {
            if (i == 0 || j == 0)   v[i][j] = 0; // 初始化
            else if (j < a->vol[i]) v[i][j] = v[i-1][j];    // 背包放不下
            else if (j >= a->vol[i]){   // 放得下
                v[i][j] = MAX(v[i-1][j], v[i-1][j-a->vol[i]] + a->value[i]);
            }
        }
    }

    for (int i = 0; i <= a->num; ++i) {
        for (int j = 0; j <= size; ++j) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }

    return v[a->num][size];
}

// ---------------------------------------------------------------------------------------------------------------------

/* 测试代码 */
int main() {
    article *a = (article*) malloc(sizeof(article));
    a->num = 4;
    a->vol = (int*) malloc(sizeof(int)*a->num);
    a->value = (int*) malloc(sizeof(int)*a->num);

    for (int i = 0; i < a->num; ++i) {
        scanf("%d%d", &a->vol[i], &a->value[i]);
    }

    printf("%d", bag(a, 9));

    return 0;
}