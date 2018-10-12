#include<stdio.h>

/* 习题3.1 得分 */
int main(){
    int s = 0, count = 1;
    char c;
    while ((c = getchar()) != '\n'){
        if(c == 'O')
            s += count++;
        else if(c == 'X')
            count = 1;
    }
    printf("%d", s);

    return 0;
}