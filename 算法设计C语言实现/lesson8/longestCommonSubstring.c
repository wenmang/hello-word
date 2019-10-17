#include <stdio.h>
#include <string.h>
#define MAX(a,b) ((a)>(b) ? (a):(b))

/**
 * 最长公共子序列【动态规划法】
 * @param s1 字符串1
 * @param s2 字符串2
 * @return 返回最长公共子序列的长度
 */
int longestCommonSubstring(char s1[], char s2[]) {
    int length[strlen(s1)+1][strlen(s2)+1];
    for (int i = 0; i <= strlen(s1); i++) {
        for (int j = 0; j <= strlen(s2); j++) {
            if (i == 0 || j == 0)
                length[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                length[i][j] = length[i - 1][j - 1] + 1;
            else
                length[i][j] = MAX(length[i][j - 1], length[i - 1][j]);
        }
    }

    return length[strlen(s1)][strlen(s2)];
}


//----------------------------------------------------------------------------------------------------------------

/*测试代码*/
int main() {
    char s1[] = "zxyxyz";
    char s2[] = "xyyzy";

    printf("%d", longestCommonSubstring(s1, s2));
    return 0;
}