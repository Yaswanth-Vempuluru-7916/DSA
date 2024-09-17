#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    // Max-heap for the left half of the data
    priority_queue<int> leftMax;
    
    // Min-heap for the right half of the data
    priority_queue<int, vector<int>, greater<int>> rightMin;

    // Function to insert an element into the heaps
    // Time Complexity: O(log n) for inserting into a heap
    // Space Complexity: O(n) for storing n elements in two heaps
    void insertHeap(int &x) {
        if (leftMax.empty()) {
            leftMax.push(x);
            return;
        }

        // Push into the appropriate heap
        if (x > leftMax.top()) {
            rightMin.push(x);
        } else {
            leftMax.push(x);
        }

        // Balance the two heaps
        balanceHeaps();
    }

    // Function to balance heaps
    // Time Complexity: O(log n) for rebalancing
    // Space Complexity: O(1) for no additional space needed
    void balanceHeaps() {
        // If rightMin has more elements, move one to leftMax
        if (rightMin.size() > leftMax.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        } 
        // If leftMax has more than one extra element, move one to rightMin
        else if (leftMax.size() > rightMin.size() + 1) {
            rightMin.push(leftMax.top());
            leftMax.pop();
        }
    }

    // Function to return the median
    // Time Complexity: O(1) for accessing the median
    // Space Complexity: O(1) for no additional space needed
    double getMedian() {
        if (leftMax.size() > rightMin.size()) {
            return leftMax.top();  // Odd number of elements, the median is in leftMax
        }

        // Even number of elements, the median is the average of the tops of both heaps
        double ans = leftMax.top() + rightMin.top();
        return ans / 2;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    int arr[] = {7,11,6,4,5,2,9,15,1,18,19,20,21};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Inserting elements and calculating medians: " << endl;
    for (int i = 0; i < n; i++) {
        sol.insertHeap(arr[i]);
        cout << "Median after inserting " << arr[i] << ": " << sol.getMedian() << endl;
    }

    return 0;
}
