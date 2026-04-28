#include <stdio.h>

void swap(int *a, int *b);

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    // Move the lowest to the left side
    // if index j less then the pivot swap j with i
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Sort the array 
int quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Swap a with b 
// if a = 1 && b = 2 then after this function a = 2 && b = 1
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int arr[6] = { 3, 2, 5, 1, 6, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}