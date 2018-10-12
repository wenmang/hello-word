#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define ERROR -12345678


typedef int elementType;
typedef struct SNode* Stack;
struct SNode{
    int top;
    elementType data[MAXSIZE];
};


Stack CreateStack (int Maxsize){    // 创建新栈
    Stack stack;
    stack = malloc(sizeof(struct SNode)*Maxsize);
    stack->top = -1;
    return stack;
}


int IsFull (Stack S, int MaxSize){  // 判断栈是否满
    if (S->top == MaxSize-1)
        return 1;
    else
        return 0;
}


int IsEmpty (Stack S){  // 判断栈是否空
    if (S->top == -1)
        return 1;
    else
        return 0;
}


void Push (Stack PtrS, elementType item){   // 压栈
    if (IsFull(PtrS, MAXSIZE)){
        printf("栈已满！");
        return;
    } else {
        PtrS->data[++(PtrS->top)] = item;
        return;
    }
}


elementType Pop (Stack PtrS){   // 出栈
    if (IsEmpty(PtrS)){
        printf("栈已空！");
        return ERROR;
    } else
        return PtrS->data[(PtrS->top)--];
}

int main(){
    int i;
    Stack stack;
    stack = CreateStack(MAXSIZE);
    for (i = 0; i < 50; i++)
        Push(stack, i);
    for (i = 0; i < 50; ++i)
        printf("%5d", Pop(stack));

    return 0;
}