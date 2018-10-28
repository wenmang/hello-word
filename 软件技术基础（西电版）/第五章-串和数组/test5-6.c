#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void StrInsert(char* s, char* t, int i) {
   char temp[1000];
   int j;
   for (j = 0; j < i; ++j)
       temp[j] = s[j];
   strcat(temp, t);
   for (j = i; j < strlen(s); ++j)
       temp[j+strlen(t)] = s[j];
   temp[j+strlen(t)] = '\0';
   printf("%s", temp);
}


int main(){
    char* s = "abcdefg";
    char* t = "ABCDEFG";
    StrInsert(s, t, 2);
}