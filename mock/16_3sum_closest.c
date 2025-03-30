// Name: Jingjing Pan
// lc link: https://leetcode.com/problems/3sum-closest/description/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int compare(const void *a, const void *b){
    return (*(int*)a -  *(int*)b);
}

int three_sum_closest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), compare);

    int min_diff = INT_MAX;
    int closest_sum = INT_MAX;

    for(int i = 0; i < numsSize - 2; i++){
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }

        int l = i + 1;
        int r = numsSize - 1;

        while (l < r){
            int curr_sum = nums[i] + nums[l] + nums[r];

            int diff = abs(target - curr_sum);

            if(diff < min_diff){
                min_diff = diff;
                closest_sum = curr_sum;
            }

            if(curr_sum < target){
                l ++;
            }else{
                r--;
            }

        } 
    }

    return closest_sum;
}

int main(){
    int nums[] = {-1,2,1,-4};
    // int nums[] = {0, 0, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 1;

    int ans = three_sum_closest(nums, numsSize, target);

    printf("The sum that is closest to the target is: %d\n", ans);
    return 0;
}