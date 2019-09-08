// 选择排序，在调用之时需要自己实现比较函数

#include <stdio.h>
#include <string.h>


// 源码部分
void Swap(void* v1, void* v2, int size) {
    char buffer[size];
    memcpy(buffer, v1, size);
    memcpy(v1, v2, size);
    memcpy(v2, buffer, size);
}

/**
 * 选择排序函数（Selection Sort）
 * @param nums  待排序数组
 * @param n 数组元素个数
 * @param numSize   元素字节大小
 * @param cmp   比较函数
 */
void SelSort(void* nums, int n, int numSize, int (*cmp)(void*, void*)) {
    for (int i = 0; i < n; ++i) {
        int tmp = i;
        for (int j = i; j < n; ++j) {
            if (cmp(nums + tmp*numSize, nums + j*numSize) > 0) {
                tmp = j;
            }
        }
        if (i != tmp)
            Swap(nums + tmp*numSize, nums + i*numSize, numSize);
    }
}

/*
-------------------------------------------------------------------------------------------
*/

// 调用示例
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
    int a[] = {1, 15, 8, 74, 65, -20, 55, 47, 100, 99};
    char* s[] = {"ab", "zcd", "ababa", "koa", "ooo"};
    SelSort(s, 5, sizeof(char*), Strcmp);
    SelSort(a, 10, sizeof(int), IntCmp);

    for (int i = 0; i < 10; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; ++i) {
        printf("%s ", s[i]);
    }
    return 0;
}