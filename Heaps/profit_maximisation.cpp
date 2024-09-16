#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to maximize profit by selling B tickets
    // Time Complexity: O(B log N), where B is the number of people and N is the number of rows (since each heap operation takes O(log N)).
    // Space Complexity: O(N), as the priority queue stores up to N elements (number of rows).
    int solve(vector<int>& A, int B) {
        // Max-heap to keep track of rows with the most vacant seats
        priority_queue<int> p(A.begin(), A.end());
        
        int sum = 0; // To store the maximum profit
        
        while (B-- && !p.empty()) {
            int top = p.top(); // Get the row with the most vacant seats
            p.pop();
            
            sum += top; // Add the number of vacant seats (profit) to the sum
            
            // Push the row back with one less seat if it's still non-zero
            if (top > 1) {
                p.push(top - 1);
            }
        }
        
        return sum;
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    
    // Test case
    vector<int> seats = {2, 5, 4};  // Number of seats in each row
    int B = 4;  // Number of people
    
    cout << "Maximum Profit: " << solution.solve(seats, B) << endl;
    
    return 0;
}
