// Name: Jingjing Pan
// lc link: https://leetcode.com/problems/single-threaded-cpu/description/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int enqueueTime;
    int processingTime;
    int index;
} Task;

typedef struct {
    int processingTime;
    int index;
} HeapNode;

typedef struct {
    HeapNode* arr;
    int size;
    int capacity;
} MinHeap;

int compareTasks(const void* a, const void* b) {
    Task* t1 = (Task*)a;
    Task* t2 = (Task*)b;
    if (t1->enqueueTime == t2->enqueueTime) {
        return t1->index - t2->index; 
    }
    return t1->enqueueTime - t2->enqueueTime;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (HeapNode*)malloc(sizeof(HeapNode) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[parent].processingTime < heap->arr[index].processingTime) break;
        if (heap->arr[parent].processingTime == heap->arr[index].processingTime &&
            heap->arr[parent].index < heap->arr[index].index) break;
        swap(&heap->arr[parent], &heap->arr[index]);
        index = parent;
    }
}

void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && (heap->arr[left].processingTime < heap->arr[smallest].processingTime ||
        (heap->arr[left].processingTime == heap->arr[smallest].processingTime &&
         heap->arr[left].index < heap->arr[smallest].index))) {
        smallest = left;
    }

    if (right < heap->size && (heap->arr[right].processingTime < heap->arr[smallest].processingTime ||
        (heap->arr[right].processingTime == heap->arr[smallest].processingTime &&
         heap->arr[right].index < heap->arr[smallest].index))) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void push(MinHeap* heap, int processingTime, int index) {
    heap->arr[heap->size].processingTime = processingTime;
    heap->arr[heap->size].index = index;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

HeapNode pop(MinHeap* heap) {
    HeapNode min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return min;
}

int* getOrder(int** tasks, int tasksSize, int* tasksColSize, int* returnSize) {
    Task sortedTasks[tasksSize];
    for (int i = 0; i < tasksSize; i++) {
        sortedTasks[i].enqueueTime = tasks[i][0];
        sortedTasks[i].processingTime = tasks[i][1];
        sortedTasks[i].index = i;
    }

    qsort(sortedTasks, tasksSize, sizeof(Task), compareTasks);

    MinHeap* minHeap = createMinHeap(tasksSize);
    
    int* result = (int*)malloc(sizeof(int) * tasksSize);
    *returnSize = 0;
    int time = 0;
    int index = 0;
    
    while (index < tasksSize || minHeap->size > 0) {
        if (minHeap->size == 0 && time < sortedTasks[index].enqueueTime) {
            time = sortedTasks[index].enqueueTime;
        }

        while (index < tasksSize && sortedTasks[index].enqueueTime <= time) {
            push(minHeap, sortedTasks[index].processingTime, sortedTasks[index].index);
            index++;
        }

        HeapNode nextTask = pop(minHeap);
        result[(*returnSize)++] = nextTask.index;
        time += nextTask.processingTime;
    }

    free(minHeap->arr);
    free(minHeap);
    return result;
}

int main() {
    int tasksArr[4][2] = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    int* tasks[4];
    for (int i = 0; i < 4; i++) {
        tasks[i] = tasksArr[i];
    }
    int tasksColSize[4] = {2, 2, 2, 2};
    int returnSize;
    int* result = getOrder(tasks, 4, tasksColSize, &returnSize);

    printf("Task execution order: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
