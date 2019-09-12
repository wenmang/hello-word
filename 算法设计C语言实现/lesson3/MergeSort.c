// 归并排序，调用时需自己实现比较函数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 * @param a 待排序数组
 * @param left 左边界
 * @param right 右数组的起始位置
 * @param rightEnd 右边界
 * @param numSize 数组元素字节数
 * @param tmp 临时数组
 * @param cmp 比较函数
 */
void Merge (void* a, int left, int right, int rightEnd, int numSize, void* tmp, int (*cmp)(void*, void*)) {
    int leftEnd = right - 1;
    int l = left, tmpSize = left;

    // 归并
    while (left <= leftEnd && right <= rightEnd) {
        if (cmp(a + left*numSize, a + right*numSize) < 0) {
            memcpy(tmp+tmpSize*numSize, a+left*numSize, numSize);
            left++;
        } else {
            memcpy(tmp+tmpSize*numSize, a+right*numSize, numSize);
            right++;
        }
        tmpSize++;
    }

    // 剩余直接复制即可
    if (left <= leftEnd)
        memcpy(tmp+tmpSize*numSize, a+left*numSize, (leftEnd-left+1)*numSize);
    else if (right <= rightEnd)
        memcpy(tmp+tmpSize*numSize, a+right*numSize, (rightEnd-right+1)*numSize);

    // 将排序完成的数组复制回原数组
    if (l <= rightEnd)
        memcpy(a+l*numSize, tmp+l*numSize, (rightEnd-l+1)*numSize);
}

void MergeSort(void* a, int left, int rightEnd, void* temp, int numSize, int (*cmp)(void*, void*)) {
    int mid;
    if (left < rightEnd) {
        mid = (left + rightEnd) / 2;
        MergeSort(a, left, mid, temp, numSize, cmp);
        MergeSort(a, mid + 1, rightEnd, temp, numSize, cmp);
        Merge(a, left, mid+1, rightEnd, numSize,temp, cmp);
    }
}

/**
 * 面向用户的函数接口
 * @param a 待排序数组
 * @param n 待排序数组的大小
 * @param numSize 数组元素字节数
 * @param cmp 比较函数
 */
void mergeSort(void* a, int n, int numSize, int (*cmp)(void*, void*)){
    void* tmpA;
    tmpA = malloc(n * numSize);
    if (tmpA != NULL){
        MergeSort(a, 0, n-1, tmpA, numSize, cmp);
        free(tmpA);
    } else {
        printf("ERROR");
    }
}


/*
 * 调用示例
 * -------------------------------------------------------------------------------------------
 */

int IntCmp(void* v1, void* v2) {
    int* ip1 = v1;
    int* ip2 = v2;
    return (*ip1 - *ip2);
}

int Strcmp(void* c1, void* c2) {
    char* s1 = *(char **) c1;
    char* s2 = *(char **) c2;
    return strcmp(s1, s2);
}

int main() {
    int a[] = {20, 5, 8, 4, 47, 54, 85, 74, 99, 100};
    char* s[] = {"ddd", "abcde", "abcd", "bcd", "ooo"};
    mergeSort(a, 10, sizeof(int), IntCmp);
    mergeSort(s, 5, sizeof(char*), Strcmp);
    for (int i = 0; i < 10; ++i) {
        printf("%d ",  a[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; ++i) {
        printf("%s ", s[i]);
    }
    return 0;
}