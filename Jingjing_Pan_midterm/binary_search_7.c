#include <stdio.h>

// Implement a function to find a target value in a sorted array, achieving a time complexity of O(logn)
int binarySearch(int arr[ ], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    int arr[ ] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    // TODO: Call the binarySearch function and print the result
    int pos = binarySearch(arr, 0, n - 1, target);
    if(pos == -1){
        printf("The target is not in this array. \n");
    }else{
        printf("The target is found at the index %d position in this array.\n", pos);
    }
    return 0;
}
