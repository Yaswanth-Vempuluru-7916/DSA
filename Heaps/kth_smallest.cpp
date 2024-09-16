#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the kth smallest element in the array
    // Time Complexity: O((n-k) log k), where n is the size of the array and k is the number of smallest elements maintained in the heap.
    // Space Complexity: O(k), since we maintain a max heap of size k.
    int kthSmallest(vector<int> &arr, int k) {
        // Initialize a max-heap (priority queue) with the first 'k' elements of the array
        priority_queue<int> p(arr.begin(), arr.begin() + k);

        // Traverse the rest of the array
        for (int i = k; i < arr.size(); i++) {
            // If the current element is smaller than or equal to the largest element in the heap
            if (arr[i] < p.top()) {
                p.pop();  // Remove the largest element
                p.push(arr[i]);  // Add the smaller element to the heap
            }
        }

        // The top of the heap is the kth smallest element
        return p.top();
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    // Test case
    vector<int> arr = {7, 10, 4, 3, 20, 15};  // Array of elements
    int k = 3;  // Find the 3rd smallest element

    cout << "The " << k << "rd smallest element is: " << solution.kthSmallest(arr, k) << endl;

    return 0;
}
