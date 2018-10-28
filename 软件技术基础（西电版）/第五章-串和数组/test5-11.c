#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 65533

struct Node{
    int j;
    int k;
}node[100];


void FindSaddlePoint( int n, int k, int a[n][k]){
    int i, j;
    int count = 1, min = MAXSIZE;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < k; ++j) {
            if (a[i][j] < min){
                min = a[i][j];
                node[i].j = j;
            }
        }
        node[i].k = min;
        min = MAXSIZE;
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < k; ++j)
            if (a[j][node[i].j] > node[i].k)
                break;
        if (j != k)
            node[i].k = 0;
    }

    for (i = 0; i < n; ++i)
        if (node[i].k != 0)
            printf("the No.%d: [%d][%d] = %d\n", count++, i, node[i].j, node[i].k);
}


int main(){
    int a[4][4] ={1, 2, 3, 4, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9, 10, 11};
    FindSaddlePoint(4, 4, a);
}