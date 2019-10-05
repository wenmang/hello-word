// 寻找数组中第K小的数

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int divide(int a[], int left, int right) {
    int low = left, high = right;

    while (1) {
        while (a[low++] < a[right]);
        while (a[--high] > a[right]);
        if (low < high) {
            swap(&a[low-1], &a[high]);
        } else
            break;
    }
    swap(&a[low-1], &a[right]);
    return low-1;
}

int select(int a[], int n, int k) {
    int left = 0, right = n-1 ,ret = divide(a, left, right);
    while (ret != k) {
        if (ret < k) {
            left = ret+1;
            ret = select(a, left, right);
        } else {
            right = ret-1;
            ret = divide(a, left, right);
        }
    }
    return a[k];
}


/*
 * 调用示例
 * -------------------------------------------------------------------------------------------
 */

int main() {
    int a[] = {1, 4, 9, 2, 3, 6};
    for (int i = 1; i < 7; ++i) {
        printf("%d ", select(a, 6, i-1));
    }
    return 0;
}