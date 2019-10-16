#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * 寻找主元，三元素选取中间主元法
 * @param a
 * @param left
 * @param right
 */
void getPivot(int a[], int left, int right) {
    int mid = left + (right-left)/2;
    if (a[left] > a[mid])
        swap(&a[left], &a[mid]);
    if (a[left] > a[right])
        swap(&a[left], &a[right]);
    if (a[mid] > a[right])
        swap(&a[mid], &a[right]);
    swap(&a[mid], &a[right - 1]);
}

/**
 * 插入排序，用来处理特例情况
 * @param a 数组
 * @param n 数组元素个数
 */
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j;
        for(j = i; j>0 && a[j-1] > temp; j--) {
            a[j] = a[j-1];
        }
        a[j] = temp;
    }
}

/**
 * 快速排序，接口可统一，但是由于俺比较懒，所以未进行统一排序接口的处理
 * @param a 数组
 * @param left 左边界
 * @param right 右边界
 */
void qSort(int a[], int left, int right){
    if (right - left > 1) {
        getPivot(a, left, right);
        int low = left, high = right - 1;
        while (1) {
            while (a[++low] < a[right - 1]);
            while (a[--high] > a[right - 1]);
            if (low < high)
                swap(&a[low], &a[high]);
            else
                break;
        }
        swap(&a[low], &a[right - 1]);
        qSort(a, left, low-1);
        qSort(a, low+1, right);
    } else
        insertionSort(a+left, right-left+1);
}

// -----------------------------------------------------------------------------------------------------------------‘

/* 测试代码 */
int main() {
    int i, a[5];

    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    qSort(a, 0, 4);
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}