#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 51
#define ERROR -1234567


typedef int elementType;
typedef struct QNode* Queue;
struct QNode{
    elementType data[MAXSIZE];
    int quelen;	// ÄÚº¬ÔªËØ¸öÊý 
    int rear;	// ¶ÓÎ²ÔªËØ 
};


Queue CreateQueue (int maxSize){    // ´´½¨ÐÂ¶ÓÁÐ
    Queue queue;
    queue = malloc(sizeof(struct QNode)*maxSize);
    queue->quelen = queue->rear = 0;
    return queue;
}


int IsFull (Queue Q){
    return Q->quelen == MAXSIZE;
}


int IsEmpty (Queue Q) {   // ÅÐ¶Ï¶ÓÁÐÊÇ·ñ¿Õ
    return Q->quelen == 0;
}


void AddQ (Queue QtrS, elementType item){   // Èë¶Ó
    if (IsFull(QtrS)){
        printf("¶ÓÁÐÂú£¡");
        return;
    } else {
        QtrS->rear = (QtrS->rear+1) % MAXSIZE;
        QtrS->quelen++;
        QtrS->data[QtrS->rear] = item;
    }
}


elementType Delete (Queue QtrS){   // ³ö¶Ó
    if (IsEmpty(QtrS)){
        printf("¶ÓÁÐ¿Õ£¡");
        return ERROR;
    } else {
    	QtrS->quelen--;
    	if (QtrS->rear - QtrS->quelen > 0)
        	return QtrS->data[QtrS->rear - QtrS->quelen];
        else
        	return QtrS->data[QtrS->quelen - QtrS->rear];
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
