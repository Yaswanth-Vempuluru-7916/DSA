#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity: O(N log N), where N is the size of the input array.
// Each insertion and extraction in the priority queue takes O(log N) time.
// We perform N such operations, so the total time complexity is O(N log N).
// Space Complexity: O(N), where N is the size of the input array, 
// due to the space required by the priority queue to store the elements.

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Priority queue to store elements in increasing order
        priority_queue<long long, vector<long long>, greater<long long>> p;
        
        // Push all elements of the array into the priority queue
        for (auto elem : arr) {
            p.push(elem);
        }
        
        long long sum = 0, cost = 0;
        
        // Continue combining ropes until only one rope remains
        while (p.size() > 1) {
            sum = 0;
            sum += p.top();  // Get the smallest rope
            p.pop();
            
            sum += p.top();  // Get the second smallest rope
            p.pop();
            
            // Push the combined rope back into the priority queue
            p.push(sum);
            
            // Add the cost of combining these two ropes
            cost += sum;
        }
        
        // Return the total cost of connecting all ropes
        return cost;
    }
};

int main() {
    Solution solution;
    
    vector<long long> ropes = {4, 3, 2, 6}; // Example input
    long long result = solution.minCost(ropes);
    
    cout << "The minimum cost of connecting the ropes is: " << result << endl;
    
    return 0;
}
