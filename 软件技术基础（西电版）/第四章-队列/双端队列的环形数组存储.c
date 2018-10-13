#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#define ERROR -1234567


typedef int elementType;
typedef struct DQNode* Deque;
struct DQNode{
    elementType data[MAXSIZE];
    int front;
    int rear;
};



Deque CreateDeque (){    // 创建新队列
    Deque deque;
    deque = malloc(sizeof(struct DQNode)*MAXSIZE);
    deque->front = -1;
    deque->rear = 0;
    return deque;
}


int IsFull (Deque D){
    return D->front == D->rear;
}


int IsEmpty (Deque D) {   // 判断队列是否空
    return D->front == -1;
}


void Push (Deque DtrS, elementType item){   // 从前往后加入
    if (IsFull(DtrS)){
        printf("队列满！");
        return;
    }
    DtrS->data[DtrS->rear] = item;
    if (DtrS->front == -1)
        DtrS->front = DtrS->rear;

    DtrS->rear = (DtrS->rear+1) % MAXSIZE;
}


void Unshift(Deque DtrS, elementType item){ // 从后往前加入
    if (IsFull(DtrS)){
        printf("队列满！");
        return;
    }
    if (DtrS->front == -1)
        DtrS->front = DtrS->rear;
    DtrS->front = (DtrS->front-1 + MAXSIZE) % MAXSIZE;
    DtrS->data[DtrS->front] = item;
}


elementType Pop (Deque DtrS){   // 从后往前弹出
    if (IsEmpty(DtrS)){
        printf("队列空！");
        return ERROR;
    }
    DtrS->rear = (DtrS->rear + MAXSIZE - 1) % MAXSIZE;  // 防止负数取模时引起歧义
    if (DtrS->rear == DtrS->front)
        DtrS->front = -1;
    return DtrS->data[DtrS->rear];
}


elementType Shift(Deque DtrS){  // 从前往后弹出
    elementType temp;
    if (IsEmpty(DtrS)){
        printf("队列空！");
        return ERROR;
    }
    temp = DtrS->data[DtrS->front];
    DtrS->front = (DtrS->front + 1) % MAXSIZE;
    if (DtrS->rear == DtrS->front)
        DtrS->front = -1;
    return temp;
}


int main(){
    int i;
    Deque deque;
    deque = CreateDeque();
    for (i = 0; i < 50; i++)
        Push(deque, i);

    for (i = 0; i < 50; i++)
        printf("%5d", Pop(deque));

    for (i = 0; i < 50; i++)
        Unshift(deque, i);

    for (i = 0; i < 50; i++)
        printf("%5d", Shift(deque));

    return 0;
}