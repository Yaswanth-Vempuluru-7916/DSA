#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity (TC):
- insert(): O(log n), where n is the number of elements in the heap. In the worst case, we may have to heapify up all the way to the root.
- delete_root(): O(log n). We replace the root and then heapify down, which takes log n time in the worst case.
- Heapify(): O(log n). The heapify operation, when called, has to move down the tree, which has a height of log n.
- print(): O(n), where n is the number of elements in the heap.

Space Complexity (SC):
- O(n), where n is the maximum size of the heap. This is due to the array used to store the heap elements.
*/

// MaxHeap class definition
class MaxHeap
{
    int *arr; // Pointer to array to store the heap
    int size; // Current size of the heap
    int max_size; // Maximum size of the heap

public:
    // Constructor to initialize heap with a given max size
    MaxHeap(int max_size)
    {
        this->max_size = max_size;
        arr = new int[max_size];
        size = 0;
    }

    // Destructor to clean up dynamically allocated memory
    ~MaxHeap()
    {
        delete[] arr;
    }

    // Insert an element into the heap
    void insert(int value)
    {
        if (size == max_size)
        {
            cout << "Heap Overflow" << endl;
            return;
        }

        int index = size;
        arr[size++] = value;

        // Heapify up to maintain heap property
        while (index > 0 && arr[(index - 1) >> 1] < arr[index])
        {
            swap(arr[index], arr[(index - 1) >> 1]);
            index = (index - 1) >> 1;
        }
    }

    // Print the heap
    void print()
    {
        if (size == 0)
        {
            cout << "No elements in the heap" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Heapify a subtree rooted at the given index
    void Heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Find the largest among root, left, and right
        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }

        // Swap and continue heapifying if root is not largest
        if (index != largest)
        {
            swap(arr[largest], arr[index]);
            Heapify(largest);
        }
    }

    // Delete the root element of the heap
    void delete_root()
    {
        if (size == 0)
        {
            cout << "Heap Underflow" << endl;
            return;
        }

        // Replace root with the last element and reduce size
        arr[0] = arr[size - 1];
        size--;

        // Heapify down from the root to restore heap property
        if (size > 0)
        {
            Heapify(0);
        }
    }
};

int main()
{
    MaxHeap h(10);
    h.insert(30);
    h.insert(18);
    h.insert(15);
    h.insert(14);
    h.insert(17);
    h.insert(13);
    h.insert(10);

    h.print(); // Output the current heap
    h.delete_root(); 
    h.print(); 
    h.delete_root(); 
    h.print(); 
    h.delete_root(); 
    h.print(); 
    h.delete_root(); 
    h.print(); 
    h.delete_root(); 
    h.print(); 
    h.delete_root(); 
    h.print(); 
    h.delete_root(); 
    h.print(); 

    return 0;
}
