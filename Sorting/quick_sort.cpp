#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Using the first element as the pivot
    int i = low + 1;      // Pointer starting from the next element
    int j = high;         // Pointer starting from the last element

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++;  // Move i to the right if arr[i] <= pivot
        while (j >= low && arr[j] > pivot) j--;    // Move j to the left if arr[j] > pivot

        if (i < j) {
            swap(arr[i], arr[j]); // Swap if pointers have not crossed
        }
    }

    swap(arr[low], arr[j]);  // Place the pivot in its correct position

    return j;  // Return the pivot index
}
void quickSort(int arr[], int low, int high)
{
    if (low >= high) {
        return;
    }

    int partition_Index = partition(arr, low, high);
    quickSort(arr, low, partition_Index - 1);
    quickSort(arr, partition_Index + 1, high);
}



int main()
{
    int arr[] = {12, 4, 5, 6, 7, 3, 1, 15 ,4,6,2,5,7,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
