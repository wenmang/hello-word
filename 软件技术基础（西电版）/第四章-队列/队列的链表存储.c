#include<stdio.h>
#include <stdlib.h>
#define ERROR -1234567


typedef int elementType;
typedef struct QNode* Queue;
struct Node{
    elementType data;
    struct Node* next;
};

struct QNode{
    struct Node* front;
    struct Node* rear;
};



Queue CreateQueue (){    // 创建新队列
    Queue queue;
    queue = malloc(sizeof(struct QNode));
    queue->front = queue->rear = NULL;
    return queue;
}


int IsEmpty (Queue Q) {   // 判断队列是否空
    return Q->front == NULL;
}


void AddQ (Queue QtrS, elementType item){   // 入队
    struct Node* tempQ;
    tempQ = malloc(sizeof(struct Node));
    tempQ->data = item;
    if (IsEmpty(QtrS)){
        QtrS->rear = QtrS->front = tempQ;
        tempQ->next = NULL;
    } else {
        QtrS->rear = QtrS->rear->next = tempQ;  // 注意此处双等之间的顺序关系
        tempQ->next = NULL;
    }
}


elementType Delete (Queue QtrS){   // 出队
    struct Node* tempQ;
    elementType temp;

    if (IsEmpty(QtrS)){
        printf("队列空！");
        return ERROR;
    }

    tempQ = QtrS->front;
    if (QtrS->front == QtrS->rear)
        QtrS->front = QtrS->rear = NULL;
    else
        QtrS->front = QtrS->front->next;
    temp = tempQ->data;
    free(tempQ);
    return temp;
}

int main(){
    int i;
    Queue queue;
    queue = CreateQueue();
    for (i = 0; i < 50; i++)
        AddQ(queue, i);

    for (i = 0; i < 50; i++)
        printf("%5d", Delete(queue));

    return 0;
}