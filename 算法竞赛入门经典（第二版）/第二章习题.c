#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void HanXin(int a, int b, int c);
void PrintTriangleDown();
void Subsequence(int n, int m);
void Decimal(int a, int b, int c);
void Permutation();

int main() {
    return 0;
}

/* 习题 2-2 */
void HanXin(int a, int b, int c){
    int i;
    for (i = 10; i < 100; i++) {
        if (i % 3 == a && i % 5 == b && i % 7 == c){
            printf("%d\n", i);
            return ;
        }
    }
    printf("No answer\n");
}

/* 2-3 输出倒三角形 */
void PrintTriangleDown(){
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++)
            printf(" ");
        for (j = 0; j < 2*(n-i)-1; j++)
            printf("#");
        printf("\n");
    }
}

/* 2-4 子序列的和 */
void Subsequence(int n, int m){
    int i;
    double s = 0.0;
    for (i = n; i <= m; i++){
        s += 1.0/(i*i);
    }
    printf("%.5f\n", s);
}

/* 2-5 分数化小数 */
void Decimal(int a, int b, int c){
    int i = 1;
    printf("%d.", a/b); // 输出非小数位
    a = a % b;
    while (i++ < c){
        a *= 10;
        printf("%d", a/b);
        a = a % b;
    }
    a *= 10;
    /* 进行四舍五入 */
    printf("%d\n", ((a%b)*10)/b >= 5 ? (a/b+1):(a/b));
}

/* 2-6 排列 */
void Permutation(){
    int i, j, k;
    bool isAppear[10];  // 定义判别数组
    for (i = 123; i < 330; i++){
        memset(isAppear, false, sizeof(isAppear));
        j = 2*i;    k = 3*i;
        // 处理数组
        isAppear[i/100] = isAppear[(i/10)%10] = isAppear[i%10] = true;
        isAppear[j/100] = isAppear[(j/10)%10] = isAppear[j%10] = true;
        isAppear[k/100] = isAppear[(k/10)%10] = isAppear[k%10] = true;
        // 判断 1-9 九个数是否都用到
        for (int l = 1; l < 10; l++) {
            if (isAppear[l] == false)
                break;
            if (l == 9)
                printf("%5d%5d%5d\n", i, j, k);
        }
    }
}