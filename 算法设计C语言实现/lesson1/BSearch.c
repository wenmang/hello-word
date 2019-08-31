// lesson 1

#include <stdio.h>
#include <string.h>


void* BSearch(void* key, void* base, int n, int elemSize, int (*cmpfn) (void*, void*)) {
	int left = 0, right = n;
	while (left <= right) {
		int mid = left + (right - left)/2;
		void* elemAddr = (char*) base + mid*elemSize;
		int tmp = cmpfn(key, elemAddr);
		if (tmp == 0) {
			return elemAddr;
		} else if (tmp < 0) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return NULL;
}

int IntCmp(void* v1, void* v2) {
	int* ip1 = v1;
	int* ip2 = v2;
	return (*ip1 - *ip2);
}

int Strcmp(void* c1, void* c2) {
    char* s1 = *(char **) c1;
    char* s2 = *(char **) c2;
    return strcmp(s1, s2);
}

int main() {
	int a[] = {1, 2, 5, 7, 15, 24, 30, 54, 66, 80, 92};
    char* s[] = {"abd", "bsd", "cde", "esd", "zzz"};
	char* key = "zzz";
    int k = 92;
    void* ret = BSearch(&key, s, 5, sizeof(char*), Strcmp);
    // void* ret = BSearch(&k, a, 11, sizeof(int), IntCmp);
	if (ret == NULL) {
		printf("目标不存在！");
	} else {
		printf("目标位置为：%llu", ((char*) ret - (char*)a) / sizeof(int) + 1)
		// printf("目标位置为：%llu", ((char*) ret - (char*)s) / sizeof(char*) + 1);
	}
	return 0;
}