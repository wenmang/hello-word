#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int strStr(char* haystack, char* needle) {  //leetcode28
    int i = 0, j = 0;
    while (haystack[i] != '\0' && needle[j] != '\0'){
        if (haystack[i] == needle[j]){
            i++;
            j++;
        }
        else if (j != 0){
            i = i - j + 1;
            j = 0;
        } else
            i++;
    }
    if (needle[j] == '\0')
        return i-j;
    return -1;
}


void Merge(int a[], int l, int r, int rightEnd, int temp[]){
    int leftEnd = r-1 ;
    int left = l, tmp = l;

    while (l <= leftEnd && r <= rightEnd){ // 当左右子序列均不空
        if (a[l] > a[r])
            temp[tmp++] = a[r++];
        else
            temp[tmp++] = a[l++];
    }
    while (l <= leftEnd)
        temp[tmp++] = a[l++];
    while (r <= rightEnd)
        temp[tmp++] = a[r++];
    for (int i = left; i < rightEnd + 1; i++)
        a[i] = temp[i];
}


void MergeSort(int a[], int l, int rightEnd, int temp[]) {
    int center;
    if (l < rightEnd) {
        center = (l + rightEnd) / 2;
        MergeSort(a, l, center, temp);
        MergeSort(a, center + 1, rightEnd, temp);
        Merge(a, l, center+1, rightEnd, temp);
    }
}


void Merge_sort(int a[], int n){
    int* tmpA;
    tmpA = malloc(n * sizeof(int));
    if (tmpA != NULL){
        MergeSort(a, 0, n-1, tmpA);
        free(tmpA);
    } else {
        printf("ERROR");
    }
}


int** threeSum(int* nums, int numsSize, int* returnSize) {  // LeetCode15
    int i = 0, j = 0, k = numsSize-1, temp, count = 0, size = 1;
    int** result=(int**)malloc(sizeof(int*)*(numsSize*(numsSize-1)*(numsSize-2))/6);
    Merge_sort(nums, numsSize);
    int x = sizeof(result);
    for (i = 0; i < numsSize; i++){
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        j = i+1;
        k = numsSize-1;
        while (j < k){
            temp = nums[i]+nums[j]+nums[k];
            if (temp == 0){
                result[count] = (int*)malloc(sizeof(int)*3);
                result[count][0] = nums[i];
                result[count][1] = nums[j];
                result[count][2] = nums[k];
                count++;
                j++;    k--;
                while (j <k && nums[j] == nums[j+1])
                    j++;
                while (j < k && nums[k] == nums[k+1])
                    k--;
            } else if (temp > 0)
                k--;
            else
                j++;
        }
    }
    *returnSize = count;
    return result;
}


int threeSumClosest(int* nums, int numsSize, int target) {  // LeetCode 16.0
    int i, j, k, max = 62233, sum;
    for (i = 0; i < numsSize-2; i++) {
        for (j = i + 1; j < numsSize-1; j++) {
            for (k = j + 1; k < numsSize; k++) {
                if (abs(nums[i] + nums[j] + nums[k] - target) < max) {
                    max = abs(nums[i] + nums[j] + nums[k] - target);
                    sum = nums[i] + nums[j] + nums[k];
                }
            }
        }
    }
    return sum;
}


int threeSumClosest1(int* nums, int numsSize, int target) { // LeetCode 16.1
    int i = 0, j, k, temp = 65533, sum;
    Merge_sort(nums, numsSize);
    for (i = 0; i < numsSize; i++){
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        j = i+1;
        k = numsSize-1;
        while (j < k){
            if (abs(nums[i]+nums[j]+nums[k]-target) < temp){
                temp = abs(nums[i]+nums[j]+nums[k]-target);
                sum = nums[i] + nums[j] + nums[k];
                if (nums[i]+nums[j]+nums[k] > target) {
                    k--;
                    continue;
                }
                else if (nums[i]+nums[j]+nums[k] < target) {
                    j++;
                    continue;
                }
                else
                    return sum;
            }
            if (nums[i]+nums[j]+nums[k] > target)
                k--;
            else if (nums[i]+nums[j]+nums[k] < target)
                j++;
        }
    }
    return sum;
}


typedef struct ListNode List;
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* swapPairs(struct ListNode* head) { // LeetCode 24
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* newHead, *p, *q, *temp;
    newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newHead->next = head;
    temp = newHead;
    p = head;
    q = head->next;
    while (q){
        /*交换操作*/
        temp->next = q;
        p->next = q->next;
        q->next = p;
        /*为下次操作准备*/
        temp = p;
        p = p->next;
        if (p)
            q =  p->next;
        else
            q = NULL;
    }

    return newHead->next;
}


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void nextPermutation(int* nums, int numsSize) { // LeetCode 31
    int i, j, temp;
    for (i = numsSize-1; i > 0; i--)
        if (nums[i] > nums[i-1]) {  // 出现顺序排列
            j = numsSize-1;
            while (nums[j] <= nums[i-1])
                j--;
            swap(&nums[j], &nums[i-1]);
            temp = numsSize-1;
            for (j = i; j < temp; ++j) {
                swap(&nums[j], &nums[temp]);
                temp--;
            }
            return;
        }

    temp = numsSize-1;
    for (j = 0; j < temp; ++j) {
        swap(&nums[j], &nums[temp]);
        temp--;
    }
}


int search(int* nums, int numsSize, int target) {   // LeetCode33
    int left = 0, right = numsSize - 1, mid, realMid, temp;

    while (left < right) {  // Find the min
        mid = left + (right - left)/2;
        if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    temp = left;
    left = 0;
    right = numsSize - 1;

    while (left <= right) { // Using Ring array to resolve
        mid = left + (right - left)/2;
        realMid = (mid + temp) % numsSize;
        if (nums[realMid] == target)
            return realMid;
        else if (nums[realMid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


int *searchRange(int* nums, int numsSize, int target, int* returnSize) {    // leetCode 34
    int* result;
    result = (int) malloc(sizeof(int*)*2);
    result[0] = -1;
    result[1] = -1;
    int left, right, mid, count = 0;
    left = 0;
    right = numsSize - 1;
    while (left < right){
        mid = left + (right-left)/2;
        if (nums[mid] == target) {
            count++;
            int min = mid;
            int max = mid;
            while (nums[--min] == target)
                count++;
            while (nums[++max] == target)
                count++;
            result[0] = min + 1;
            result[1] = max - 1;
            *returnSize = count;
            return result;
        }
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return result;
}


int searchInsert(int* nums, int numsSize, int target) { // leetCode35
    int left = 0, right = numsSize -1, mid;
    while (left <= right){
        mid = left + (right-left)/2;
        if (nums[mid] == target)
            return nums[mid];
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}