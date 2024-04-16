#include <stdio.h>

// Function to perform heapify down operation
void heapifyDown(int arr[], int index, int heapSize) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Find the smallest element among the current node and its children
    if (left < heapSize && arr[left] < arr[smallest])
        smallest = left;
    if (right < heapSize && arr[right] < arr[smallest])
        smallest = right;

    // If the smallest element is not the current node, swap and heapify down
    if (smallest != index) {
        int temp = arr[index];
        arr[index] = arr[smallest];
        arr[smallest] = temp;
        // Recursively call heapifyDown on the swapped node
        heapifyDown(arr, smallest, heapSize);
    }
}

// Function to build a heap from an array
void buildHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify down
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapifyDown(arr, i, n);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Build the heap
    buildHeap(arr, n);

    printf("Heapified array: ");
    printArray(arr, n);

    return 0;
}
