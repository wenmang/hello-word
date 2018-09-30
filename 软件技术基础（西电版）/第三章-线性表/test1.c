/**
 *  习题 1
 *   此题的实现主要过程为main()函数 judge 后的循环判断，
 *   
 *   int Min(int a, int b) 函数为实现过程中的辅助函数
 */


#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

struct LNode{
    int data[MAXSIZE];
    int last;
};
typedef struct LNode* L;


int Min(int a, int b);
int main(){
    int n, m, i, j;
    L A, B;
    A = (L)malloc(sizeof(struct LNode));
    B = (L)malloc(sizeof(struct LNode));

    /* input data */
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
        scanf("%d", &A->data[i]);
    A->last = --n;
    for(i = 0; i < m; i++)
        scanf("%d", &B->data[i]);
    B->last = --m;

    /* judge */
    for (i = 0; i <= Min(A->last, B->last); i++)
        if (A->data[i] != B->data[i])
            break;
    if (i == Min(A->last, B->last)+1){
        if (n == m)
            printf("0");
        else
            printf("%d", A->last < B->last ? -1:1);
    }
    else
        printf("%d", A->data[i] < B->data[i] ? -1:1);
}


int Min(int a, int b){  /* return a smaller number in a and b */
    return a > b ? b:a;
}
