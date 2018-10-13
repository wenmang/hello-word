#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 51
#define ERROR -1234567


typedef int elementType;
typedef struct QNode* Queue;
struct QNode{
    elementType data[MAXSIZE];
    int front;
    int rear;
};


Queue CreateQueue (int maxSize){    // 创建新队列
    Queue queue;
    queue = malloc(sizeof(struct QNode)*maxSize);
    queue->front = queue->rear = 0;
    return queue;
}


int IsFull (Queue Q){
    return Q->front == (Q->rear+1) % MAXSIZE;
}


int IsEmpty (Queue Q) {   // 判断队列是否空
    return Q->front == Q->rear;
}


void AddQ (Queue QtrS, elementType item){   // 入队
    if (IsFull(QtrS)){
        printf("队列满！");
        return;
    } else {
        QtrS->rear = (QtrS->rear+1) % MAXSIZE;
        QtrS->data[QtrS->rear] = item;
    }
}


elementType Delete (Queue QtrS){   // 出队
    if (IsEmpty(QtrS)){
        printf("队列空！");
        return ERROR;
    } else {
        QtrS->front = (QtrS->front+1) % MAXSIZE;
        return QtrS->data[QtrS->front];
    }
}

int main(){
    int i;
    Queue queue;
    queue = CreateQueue(MAXSIZE);
    for (i = 0; i < 50; i++)
        AddQ(queue, i);

    for (i = 0; i < 20; i++)
        printf("%5d", Delete(queue));

    for (i = 0; i < 10; i++)
        AddQ(queue, i);

    for (i = 0; i < 40; i++)
        printf("%5d", Delete(queue));

    return 0;
}