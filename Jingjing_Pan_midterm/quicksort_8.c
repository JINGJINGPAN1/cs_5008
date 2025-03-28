#include <stdio.h>
// TODO: Implement the swap function
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// TODO: Implement the partition function
int partition(int* arr, int left, int right){
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5}; // You can modify this array for testing
    // int arr[] = {2, 3, 4, 1};
    // int arr[] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int pi = partition(arr, 0, n - 1);
    printf("Partitioned array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Pivot element is at index: %d\n", pi);
    return 0;
}
