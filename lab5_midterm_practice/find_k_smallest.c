#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int arr[], int low, int high, int *left, int *right){
    int rd_index= low+ rand()%(high-low + 1);
    int pivot = arr[rd_index];
    int i_small= low;
    int i_large = high;
    int i = low;
    while(i <=i_large){
        if(arr[i]< pivot){
            swap(&arr[i], &arr[i_small]);
            i++;
            i_small++;
        } else if(arr[i]> pivot){
            swap(&arr[i], &arr[i_large]);
            i_large--;
        } else {
        i++;
        }
    }
    *left =i_small;
    *right=i_large;

}

int quickselect(int arr[], int low, int high, int k){
    int orig_k = k;
    while(low < high){
        int i_small, i_large;
        partition(arr, low, high, &i_small, &i_large);

        if(i_small >= k){
            high = i_small - 1;
        }else if(k >= i_large){
            low = i_large + 1;
            k -= (i_large + 1);
        }else{
            return arr[k - 1];
        }
    }

    return arr[orig_k - 1];
}

// int find_k_smallest(int arr[], int n, int k){
//     quickselect(arr, 0, n - 1, k);
//     return arr[k - 1];
// }

int main() {
    int arr[] = {7, 10, 14, 3, 5, 20, 15}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; 

    int result = quickselect(arr, 0, n - 1, k);
    printf("The %d-th smallest element is: %d\n", k, result);

    return 0;
}