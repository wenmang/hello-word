// 基数排序，int

#include <stdlib.h>
#include <stdio.h>

int findMax(int a[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (a[i] > max)
            max  = a[i];
    }
    return max;
}

int getDigit(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

void bucketSort(int a[], int n) {
    int max = findMax(a, n);
    int digit = getDigit(max);

    int bucket[10][n];
    int flag[10] = {0};
    int k = 1, m = 0;
    for (int i = 0; i < digit; i++) {
        // 从低位到高位，按位归类到桶
        for (int j = 0; j < n; ++j) {
            int tmp = (a[j]/k) % 10;
            bucket[tmp][flag[tmp]] = a[j];
            flag[tmp]++;
        }

        // 重排数组
        for (int j = 0; j < n; ++j) {
            if (flag[j] != 0) {
                for (int l = 0; l < flag[j]; ++l) {
                    a[m++] =  bucket[j][l];
                }
            }
            flag[j] = 0;
        }

        k *= 10;
        m = 0;
    }
}

/*
 * 调用示例
 * -------------------------------------------------------------------------------------------
 */

int main() {
    int a[] = {10, 9, 78, 29, 62, 81, 97, 64, 0, 6};
    bucketSort(a, 10);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", a[i]);
    }
}