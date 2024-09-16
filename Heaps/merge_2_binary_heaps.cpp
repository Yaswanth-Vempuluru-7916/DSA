#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Heapify function to maintain the max-heap property
    // Time Complexity: O(log n), where n is the size of the heap
    void Heapify(vector<int>& heap, int index, int n) {
        int largest = index;         // Initialize largest as root
        int left = 2 * index + 1;    // Left child
        int right = 2 * index + 2;   // Right child
        
        // If left child is larger than root
        if (left < n && heap[largest] < heap[left]) {
            largest = left;
        }
        
        // If right child is larger than the largest so far
        if (right < n && heap[largest] < heap[right]) {
            largest = right;
        }
        
        // If the largest is not the root, swap and continue heapifying
        if (largest != index) {
            swap(heap[largest], heap[index]);
            Heapify(heap, largest, n);
        }
    }

    // Function to merge two heaps into one max-heap
    // Time Complexity: O((n+m) log(n+m)), where n and m are the sizes of the input heaps
    // Space Complexity: O(n+m), as we use extra space to store the merged heap
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Merging both heaps into one array
        vector<int> mergedHeap;
        int size = n + m;
        
        // Insert elements from both heaps into the merged array
        for (auto elem : a) mergedHeap.push_back(elem);
        for (auto elem : b) mergedHeap.push_back(elem);
        
        // Heapify process: convert merged array into a max heap
        for (int i = (size / 2) - 1; i >= 0; i--) {
            Heapify(mergedHeap, i, size);
        }
        
        return mergedHeap;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    // Test case
    vector<int> heap1 = {10, 5, 6, 2};
    vector<int> heap2 = {12, 7, 9};
    
    vector<int> merged = solution.mergeHeaps(heap1, heap2, heap1.size(), heap2.size());
    
    cout << "Merged Max-Heap: ";
    for (int elem : merged) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
1. Building the max-heap (Heapify) for the merged array takes O(log(n+m)) for each element.
2. Therefore, the overall time complexity is O((n+m) log(n+m)), where n is the size of the first heap, and m is the size of the second heap.

Space Complexity:
1. The space complexity is O(n+m), as we store the merged heap in a new vector.
*/
