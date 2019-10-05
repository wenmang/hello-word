#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))

int max = INT_MIN, min = INT_MAX;

/**
 * 寻找数组中的最大和最小元素
 *  改两次遍历为两两比较，将时间复杂度降低至 O(3n/2)
 * @param a 数组
 * @param n 数组大小
 */
void minMax(int a[], int n) {
    int x, y;
    for (int i = 0; i < n; i+=2) {
        if (a[i] > a[i+1]) {
            x = a[i];
            y = a[i+1];
        } else{
            x = a[i+1];
            y = a[i];
        }

        max = MAX(max, x);
        min = MIN(min, y);
    }
}


/*
 * 调用示例
 * -------------------------------------------------------------------------------------------
 */

int main() {
    int a[] = {2, 34, 1, 0, -10, 9};
    minMax(a, 6);
    printf("%d   %d", min, max);

    return 0;
}