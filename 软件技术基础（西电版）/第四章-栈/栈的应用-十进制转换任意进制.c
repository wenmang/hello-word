#include<stdio.h>
#include <stdlib.h>


typedef int elementType;
typedef struct SNode* Stack;
struct SNode{
    elementType data;
    Stack *next;
};


Stack CreateStack (){    // 创建新栈
    Stack stack;
    stack = malloc(sizeof(struct SNode));
    stack->next = NULL;
    return stack;
}


int IsEmpty (Stack S) {   // 判断栈是否空
    return S->next == NULL;
}


void Push (Stack PtrS, elementType item){   // 压栈
    Stack TempS;
    TempS = malloc(sizeof(struct SNode));
    TempS->data = item;
    TempS->next = PtrS->next;
    PtrS->next = TempS;
}


elementType Pop (Stack PtrS){   // 出栈
    Stack TempS;
    elementType temp;
    if (IsEmpty(PtrS)){
        printf("栈已空！");
        return ERROR;
    } else {
        TempS = PtrS->next;
        PtrS->next = TempS->next;
        temp = TempS->data;
        free(TempS);
        return temp;
    }
}

int main(){
    int i, j;
    Stack stack;
    stack = CreateStack();
    while(scanf("%d%d", &j, &i) == 2 && i != 0){
        while (j != 0){
            Push(stack, j%i);
            j /= i;
        }

        while (!(IsEmpty(stack))){
            int m = Pop(stack);
            if (m < 10)
                printf("%d", m);
            else
                printf("%c", m-10+'A');
        }
    }

    return 0;
}