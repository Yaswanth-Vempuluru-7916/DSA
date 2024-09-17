#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to merge k sorted arrays.
    // Time Complexity: O(K^2 * log(K)), where K is the size of each array, and there are K arrays.
    // Space Complexity: O(K), since we store K elements in the priority queue at any time.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<pair<int, pair<int, int>>> temp; // To hold the first element from each array
        vector<int> ans; // To store the final merged array
        
        // Push the first element from each array into the priority queue
        for (int i = 0; i < K; i++) {
            temp.push_back({arr[i][0], {i, 0}});
        }
        
        // Min-heap (priority queue) to store elements with the smallest at the top
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

        pair<int, pair<int, int>> pairr;
        int data, i, j;

        // While the heap is not empty
        while (!p.empty()) {
            pairr = p.top();
            data = pairr.first;
            i = pairr.second.first;
            j = pairr.second.second;
            p.pop(); // Remove the smallest element
            ans.push_back(data); // Add the smallest element to the result
            
            // If there's another element in the same row, push it into the heap
            if (j + 1 < K) {
                p.push({arr[i][j + 1], {i, j + 1}});
            }
        }

        return ans; // Return the merged array
    }
};

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

// Main function to test the solution
int main() {
    int K = 3;
    vector<vector<int>> arr = {
        {1, 3, 5},
        {2, 4, 6},
        {0, 9, 10}
    };

    Solution sol;
    vector<int> mergedArray = sol.mergeKArrays(arr, K);
    
    cout << "Merged Array: ";
    printArray(mergedArray);

    return 0;
}
