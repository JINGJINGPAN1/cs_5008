#include<stdio.h>

void bubbleSort(int arr[], int n){
    int i, j;
    
    for(int i = 0; i < n - 1; i++){
        int is_swapped = 0;

        for(int j = 0; j < n - 1- i; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                is_swapped = 1;
            }
        }

        if(is_swapped == 0){
            break;
        }
    }
}

int main(){
    int arr[] = {3, 4, 5, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}