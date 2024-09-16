#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the last stone weight
    // Time Complexity: O(N log N), where N is the number of stones. Each heap operation (pop, push) takes O(log N).
    // Space Complexity: O(N), as we are storing all the stones in the priority queue.
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p(stones.begin(), stones.end()); // Max heap
        
        int first = 0, second = 0;
        
        while (p.size() > 1) {
            first = p.top();  // Heaviest stone
            p.pop();
            second = p.top();  // Second heaviest stone
            p.pop();
            
            int diff = first - second;
            if (diff > 0) {  // Only push the difference if non-zero
                p.push(diff);
            }
        }

        return p.empty() ? 0 : p.top();  // Return the last stone or 0 if empty
    }
};

// Optimized Solution
class OptimizedSolution {
public:
    // Optimized Function using direct initialization
    // Time Complexity: O(N log N), as heap operations (pop, push) take O(log N).
    // Space Complexity: O(N), since the heap stores all stones.
    int lastStoneWeightOptimized(vector<int>& stones) {
        // Direct initialization of priority queue
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int first = pq.top();  // Heaviest stone
            pq.pop();
            int second = pq.top();  // Second heaviest stone
            pq.pop();
            
            if (first != second) {
                pq.push(first - second);  // Push the difference if they are not equal
            }
        }
        
        return pq.empty() ? 0 : pq.top();  // Return last stone weight or 0 if no stones are left
    }
};

// Main function to test both approaches
int main() {
    Solution solution;
    OptimizedSolution optimizedSolution;
    
    vector<int> stones = {2, 7, 4, 1, 8, 1};  // Example test case
    
    // Test the original solution
    cout << "Original Solution Last Stone Weight: " << solution.lastStoneWeight(stones) << endl;
    
    // Test the optimized solution
    cout << "Optimized Solution Last Stone Weight: " << optimizedSolution.lastStoneWeightOptimized(stones) << endl;
    
    return 0;
}
