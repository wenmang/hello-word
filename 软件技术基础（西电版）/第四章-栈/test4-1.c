#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define ERROR -12345678


typedef int elementType;
typedef struct SNode* Stack;
struct SNode{
    elementType data;
    Stack *next;
};


Stack CreateStack (){    // ´´½¨ÐÂÕ»
    Stack stack;
    stack = malloc(sizeof(struct SNode));
    stack->next = NULL;
    return stack;
}


int IsEmpty (Stack S) {   // ÅÐ¶ÏÕ»ÊÇ·ñ¿Õ
    return S->next == NULL;
}


void Push (Stack PtrS, elementType item){   // Ñ¹Õ»
    Stack TempS;
    TempS = malloc(sizeof(struct SNode));
    TempS->data = item;
    TempS->next = PtrS->next;
    PtrS->next = TempS;
}


elementType Pop (Stack PtrS){   // ³öÕ»
    Stack TempS;
    elementType temp;
    if (IsEmpty(PtrS)){
        printf("Õ»ÒÑ¿Õ£¡");
        return ERROR;
    } else {
        TempS = PtrS->next;
        PtrS->next = TempS->next;
        temp = TempS->data;
        free(TempS);
        return temp;
    }
}

bool IsHui(char *s){
	Stack stack;
	int i, j, n, k = strlen(s) / 2;
	stack = CreateStack();
	for (i = 0; i < k; i++)
		Push(stack, s[i]);
	if (strlen(s) % 2 == 0){
		for (j = i; j < strlen(s); j++){
			n = Pop(stack);
			if (n != s[j])
				break;
		}
		if (j == strlen(s))
			return true;
		else return false;
	} else {
		for (j = i+1; j < strlen(s); j++){
			n = Pop(stack);
			if (n != s[j])
				break;
		}
		if (j == strlen(s))
			return true;
		else return false;
	}
}

int main(){
    char *s = "goog";
    printf("%d", IsHui(s));
}
