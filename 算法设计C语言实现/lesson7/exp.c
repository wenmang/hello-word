// 自己实现次方函数

#include <stdio.h>
#include <stdlib.h>

double exp(double x, int n) {
    double base = x;
    double ret = 1.0;
    while (n != 0) {
        if ((n&1) == 1) {
            ret *= base;
        }
        base *= base;
        n >>= 1;
    }
    return ret;
}

/*
 * 调用示例
 * -------------------------------------------------------------------------------------------
 */

int main() {
    double x = 4.0;
    int i = 2;
    printf("%lf", exp(x, i));

    return 0;
}