#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the kth largest element in the array
    // Time Complexity: O((n-k) log k), where n is the size of the array and k is the number of largest elements maintained in the heap.
    // Space Complexity: O(k), since we maintain a min-heap of size k.
    int kthLargest(vector<int> &arr, int k) {
        // Initialize a min-heap (priority queue) with the first 'k' elements of the array
        priority_queue<int, vector<int>, greater<int>> p(arr.begin(), arr.begin() + k);

        // Traverse the rest of the array
        for (int i = k; i < arr.size(); i++) {
            // If the current element is larger than the smallest element in the heap
            if (arr[i] > p.top()) {
                p.pop();  // Remove the smallest element
                p.push(arr[i]);  // Add the larger element to the heap
            }
        }

        // The top of the heap is the kth largest element
        return p.top();
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    // Test case
    vector<int> arr = {7, 10, 4, 3, 20, 15, 100, 99, 69};  // Array of elements
    int k = 3;  // Find the 3rd largest element

    cout << "The " << k << "rd largest element is: " << solution.kthLargest(arr, k) << endl;

    return 0;
}
