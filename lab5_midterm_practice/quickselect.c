#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int arr[], int low, int high, int *left, int *right) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex]; 
    int i_small = high;  
    int i = low;  
    int i_large = low;

    while (i <= i_small) {
        if (arr[i] < pivot) {
            swap(&arr[i_small], &arr[i]);
            i_small--;
        } else if (arr[i] > pivot) {
            swap(&arr[i], &arr[i_large]);
            i++;
            i_large++;
        } else {
            i++;
        }
    }

    *left = i_large;
    *right = i_small;
}

void quickSelect(int arr[], int low, int high, int k) {

    while(low < high){
        int left, right;
        partition(arr, low, high, &left, &right);

        if (high - right <= k) {
            return quickSelect(arr, right + 1, high, k);
        } else if (high - left + 1 <= k) {
            return; 
        } else {
            return quickSelect(arr, low, left - 1, k- (high - left + 1));
        }
    }
}

int findKthSmallest(int arr[], int n, int k) {
    // srand(time(NULL));
    quickSelect(arr, 0, n - 1, k);
    return arr[n - k];
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; 

    int result = findKthSmallest(arr, n, k);
    printf("The %d-th smallest element is: %d\n", k, result);

    return 0;
}