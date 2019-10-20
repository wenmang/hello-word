#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) ((a)<(b) ? (a):(b))

/**
 * 多源最短路，Floyd算法的实现
 * @param weight 边的权重矩阵
 * @param n 边数，也就是weight数组的行列数
 * @return 
 */
int** floyd(int** weight, int n) {
    int** ret = (int**) malloc(sizeof(int*)*n);
    for (int i = 0; i < n; ++i) {
        ret[i] = (int*) malloc(sizeof(int)*n);
        for (int j = 0; j < n; ++j) {
            ret[i][j] = weight[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ret[i][j] = MIN(ret[i][j], ret[i][k]+ret[k][j]);
            }
        }
    }

    return ret;
}


//----------------------------------------------------------------------------------------------------------------------

/* 测试代码 */
int main() {
    int** wight = (int**) malloc(sizeof(int*)*3);
    int n;
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        wight[i] = (int*) malloc(sizeof(int)*n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &wight[i][j]);
        }
    }

    int** ret = floyd((int **) wight, 3);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }

    return 0;
}