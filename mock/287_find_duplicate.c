// Name: Jingjing Pan
// lc link: https://leetcode.com/problems/find-the-duplicate-number/description/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int find_duplicate(int* nums, int numsSize){
    int tortoise = nums[0];
    int hare = nums[0];

    while(true){
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];

        if(tortoise == hare){
            break;
        }
    }

    tortoise = nums[0];
    while (tortoise != hare){
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;

}

int main(){
    int nums[] = {1,3,4,2,2};
    // int nums[] = {3,1,3,4,2};
    // int nums[] = {3,3,3,3,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int ans = find_duplicate(nums, numsSize);

    printf("The duplicate number is %d\n", ans);

    return 0;


}