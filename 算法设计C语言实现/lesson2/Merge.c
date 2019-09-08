// 归并函数，调用时需自己实现比较函数

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 源码部分

/**
 * 
 * @param num1 数组1
 * @param num2 数组2
 * @param n1 数组1大小
 * @param n2 数组2大小
 * @param numSize 数组元素字节数 
 * @param cmp 比较函数
 * @return 
 */
void* Merge (void* num1, void* num2, int n1, int n2, int numSize, int (*cmp)(void*, void*)) {
    char* ret = (char*) malloc((n1 + n2) * numSize);
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (cmp(num1 + i*numSize, num2 + j*numSize) < 0) {
            memcpy(ret+(i+j)*numSize, num1+i*numSize, numSize);
            i++;
        } else {
            memcpy(ret+(i+j)*numSize, num2+j*numSize, numSize);
            j++;
        }
    }
    if (i != n1) {
        memcpy(ret+(i+j)*numSize, num1+i*numSize, (n1-i)*numSize);
    } else {
        memcpy(ret+(i+j)*numSize, num2+j*numSize, (n2-j)*numSize);
    }

    return ret;
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
    int a1[] = {-20, 1, 8, 15, 47, 55, 65, 74, 99, 100};
    int a2[] = {-20, 1, 8, 15, 47, 55, 65, 74, 99, 100};
    char* s1[] = {"ab", "abc", "abcd", "bcd", "ooo"};
    char* s2[] = {"ab", "abc", "abcd", "bcd", "ooo"};

    int* a = Merge(a2, a1, 10, 10, sizeof(int), IntCmp);
    char** s = Merge(s1, s2, 5, 5, sizeof(char*), Strcmp);
    for (int i = 0; i < 20; ++i) {
        printf("%d ",  a[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        printf("%s ", s[i]);
    }
    return 0;
}