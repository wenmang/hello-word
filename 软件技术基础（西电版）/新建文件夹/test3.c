/**
 *  习题 3
 *	 此题的实现过程为 L Insert(L list, int x) 函数
 *	 
 *	 其余函数及操作均为验证函数是正确而创建
 */

#include<stdio.h>
#include<stdlib.h>


typedef struct LNode* L;
struct LNode{
    int data;
    L next;
};


L Insert(L list, int x);
int main(){
    int i;
    L test, ptrL;
    test = (L)malloc(sizeof(struct LNode));
    for (i = 10; i > 0; i++)	// make a list from small to big
        test = Insert(test, i);

    ptrL = test->next;
    for (i = 0; i < 10; ++i) {	// print the result
        printf("%d ", ptrL->data);
        ptrL = ptrL->next;
    }
    return 0;
}


/* Insert with a order： from small to big */
L Insert(L list, int x){
    L p, p1;
    p = list->next;
    p1 = list;

    /* find the address */
    while (p->data < x && p != NULL){
        p = p->next;
        p1 = p1->next;
    }

    /* create the new Node */
    L newNode;
    newNode = (L)malloc(sizeof(struct LNode));
    newNode->data = x;

    /* insert */
    if (p == NULL){
        p->next = newNode;
        newNode->next = NULL;
    } else {
        p1->next = newNode;
        newNode->next = p;
    }
    return list;
}