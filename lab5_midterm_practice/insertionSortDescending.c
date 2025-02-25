#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSortDescending(int arr[], int n, int* comparisons, int* swaps){

    for(int i = 1; i < n; i++){
        *comparisons = 0;
        *swaps = 0;
        int key = arr[i];
        int j = i - 1;

        (*comparisons) += 1;
        while(j >= 0 && arr[j] < key){
            (*comparisons) += 1;

            arr[j + 1] = arr[j];
            (*swaps) += 1;

            j -= 1;
        }

        arr[j + 1] = key;
        (*swaps) += 1;
    }


}


int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons, swaps;
    insertionSortDescending(arr, n, &comparisons, &swaps);
    printf("Sorted array in descending order: ");
    for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Total comparisons: %d\n", comparisons);
    printf("Total swaps: %d\n", swaps);
    return 0;
}
