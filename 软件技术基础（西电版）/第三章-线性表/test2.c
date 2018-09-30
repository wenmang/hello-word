/**
 *  习题 2
 *   此题的实现过程为 void Reverse(L list) 和 void Reverse1(L1 list) 函数，前者为 倒置顺序存储 后者为倒置链式存储
 *
 *   其余函数及操作均为验证此题是否正确而创建，两个验证的代码块均已被注释
 */


#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

/* 顺序存储结构体 */
typedef struct LNode* L;
struct LNode{
    int data[MAXSIZE];
    int last;
};


/* 链式存储结构体 */
typedef struct LNode1* L1;
struct LNode1{
    int data;
    L1 next;
};

/*

// 此为验证 顺序存储线性表 的逆置
void Reverse(L list);
int main(){
    L test = (L)malloc(sizeof(struct LNode));
    int i;
    for (i = 0; i < 50; i++)
        test->data[i] = i;
    test->last = 49;

    Reverse(test);
    for (i = 0; i < 50; i++) {
        printf("%d ", test->data[i]);
    }
}
 */

/*

// 此块为验证链式存储的倒置是否能实现
L1 LinkedListCreate();
void Reverse1(L1 list);
int main(){
    int i;
    L1 test, ptrL;
    test = LinkedListCreate();
    Reverse1(test);

    ptrL = test->next;
    for (i = 0; i < 10; ++i) {
        printf("%d ", ptrL->data);
        ptrL = ptrL->next;
    }
}
*/

L1 LinkedListCreate() { // 创建链式存储线性表 前置
    L1 Head, p;
    int x = 1;
    Head = (L1)malloc(sizeof(struct LNode1));
    Head->next=NULL;
    while (x != 11) {
        p = (L1)malloc(sizeof(struct LNode1));
        p->data = x;
        p->next = Head->next;
        Head->next = p;
        x++;
    }
    return Head;
}

void Reverse(L list){   // 倒置 顺序存储的线性表
    int i = 0, j = list->last;
    while (i <= j){ // 采取位操作方式 无有中间变量
        list->data[i] = list->data[i] ^ list->data[j];
        list->data[j] = list->data[i] ^ list->data[j];
        list->data[i] = list->data[i] ^ list->data[j];
        i++; j--;
    }
}


void Reverse1(L1 list){ // 倒置 链式存储的线性表
    L1 p, q;
    p = list->next;
    q = p->next;
    p->next = NULL;
    while (q){
        p = q;
        q = p->next;
        p->next = list->next;
        list->next = p;
    }
}