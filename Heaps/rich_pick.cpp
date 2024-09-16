#include <iostream>
#include <vector>
#include <queue>
#include <cmath> // for sqrt and floor
using namespace std;

class Solution {
public:
    // Function to pick gifts and minimize the total sum after k operations
    // Time Complexity: O(k log N + N log N), where N is the number of elements in 'gifts'. 
    // Each priority queue operation (pop and push) takes O(log N), and the final summation takes O(N log N).
    // Space Complexity: O(N), as we store N elements in the priority queue.
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> p(gifts.begin(), gifts.end());  // Max-heap initialized with all gifts
        long long ans = 0;

        // Perform k operations of picking the largest gift and replacing it with its floor square root
        while (k > 0 && !p.empty()) {
            int top = p.top();  // Get the largest gift
            p.pop();
            int sqrtt = floor(sqrt(top));  // Replace the largest gift with its floor square root
            p.push(sqrtt);  // Push the new value back into the heap
            k--;
        }

        // Calculate the sum of remaining gifts in the priority queue
        while (!p.empty()) {
            ans += p.top();
            p.pop();
        }

        return ans;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    // Test case
    vector<int> gifts = {9, 16, 25};  // Example gifts
    int k = 2;  // Number of operations

    cout << "Total sum after picking gifts: " << solution.pickGifts(gifts, k) << endl;

    return 0;
}
