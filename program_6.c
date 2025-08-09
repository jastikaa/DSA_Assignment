#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void mheapify(int arr[], int n, int i) {
    int largest = i;      
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        mheapify(arr, n, largest);
    }
}

void bldmxHeap(int arr[], int n) {
    for (int i = n / 2 -1; i >= 0; i--) {
        mheapify(arr, n, i);
    }
}

void miheapify(int arr[], int n, int i) {
    int smallest = i;      
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        miheapify(arr, n, smallest);
    }
}

void bldminHeap(int arr[], int n) {
    for (int i = n / 2 -1; i >= 0; i--) {
        miheapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {34, 23, 12, 3, 17, 8, 9, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arrMin[n];
    for(int i = 0; i < n; i++) {
        arrMin[i] = arr[i];
    }
    printf("Original array:\n");
    printArray(arr, n);

    bldmxHeap(arr, n);
    printf("Max Heap:\n");
    printArray(arr, n);

    bldminHeap(arrMin, n);
    printf("Min Heap:\n");
    printArray(arrMin, n);

    return 0;
}
