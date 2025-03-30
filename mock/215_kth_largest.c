// Name: Jingjing Pan
// lc link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int* nums, int l, int r, int* p1, int* p2) {
    int pivot_index = l + rand() % (r - l + 1);
    int pivot = nums[pivot_index];

    int i_small = l, i_large = r, i = l;

    while (i <= i_large) {
        if (nums[i] < pivot) {
            swap(&nums[i], &nums[i_small]);
            i_small++;
            i++;
        } else if (nums[i] > pivot) {
            swap(&nums[i], &nums[i_large]);
            i_large--;
        } else {
            i++;
        }
    }

    *p1 = i_small;
    *p2 = i_large;
}

void quickselect(int* nums, int l, int r, int k) {
    while (l < r) {  
        int i_small, i_large;
        partition(nums, l, r, &i_small, &i_large);

        int right_size = r - i_large;         
        int middle_size = i_large - i_small + 1;  

        if (right_size >= k) {
            l = i_large + 1;  
        } else if (right_size + middle_size >= k) {
            return;  
        } else {
            r = i_small - 1;
            k -= (right_size + middle_size); 
        }
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    srand(time(0));
    quickselect(nums, 0, numsSize - 1, k);
    return nums[numsSize - k];  
}

int main() {
    int nums[] = {3, 3, 3};
    int k = 2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int ans = findKthLargest(nums, numsSize, k);
    printf("The %dth largest num is: %d\n", k, ans);

    return 0;
}
