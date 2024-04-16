
// In the context of an array, the term "majority" refers to an element that appears more than half of the total number of elements in the array.

#include <stdio.h>

// Function to find the majority element in an array
int findMajority(int arr[], int n) {
    int candidate = arr[0];
    int count = 1;
    
    // Step 1: Find potential candidate
    for (int i = 1; i < n; i++) {
        if (arr[i] == candidate)
            count++;
        else {
            count--;
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            }
        }
    }
    
    // Step 2: Check if candidate is the majority element
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }
    
    if (count > n / 2)
        return candidate; // Majority element found
    else
        return -1; // No majority element
}

int main() {
    int arr[] = {2, 2, 3, 4, 2, 2, 5, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int majority = findMajority(arr, n);
    
    if (majority != -1)
        printf("Majority element: %d\n", majority);
    else
        printf("No majority element\n");
    
    return 0;
}
