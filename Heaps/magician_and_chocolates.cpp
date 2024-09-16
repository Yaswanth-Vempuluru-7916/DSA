#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Approach 1: Using a loop to insert elements into the priority queue.
    // Time Complexity: O(A log N), where A is the number of units of time and N is the number of bags.
    // Space Complexity: O(N), since we use a priority queue to store the chocolates in the bags.
    int nchocWithLoop(int A, vector<int> &B)
    {
        priority_queue<int> pq;

        // Insert all elements into the priority queue
        for (auto elem : B)
        {
            pq.push(elem);
        }

        long long ans = 0;
        const int MOD = 1000000007;

        // Process A units of time
        while (A--)
        {
            int maxChoco = pq.top();
            pq.pop();
            ans = (ans + maxChoco) % MOD; // Add chocolates and take modulo
            pq.push(maxChoco / 2);        // Refill the bag with floor(Bi/2) chocolates
        }

        return ans;
    }

    // Approach 2: Using direct initialization of the priority queue.
    // Time Complexity: O(A log N), where A is the number of units of time and N is the number of bags.
    // Space Complexity: O(N), since we use a priority queue to store the chocolates in the bags.
    int nchocOptimized(int A, vector<int> &B)
    {
        // Directly initialize the priority queue with the array elements
        priority_queue<int> p(B.begin(), B.end());

        long long ans = 0;
        const int MOD = 1000000007;

        // Process A units of time
        while (A && !p.empty())
        {
            // Get the maximum chocolates from the top of the priority queue
            int maxChoc = p.top();
            p.pop();

            // Add the chocolates eaten to the result
            ans += maxChoc;

            // If the top value is greater than 1, push floor(Bi/2) back into the queue
            if (maxChoc / 2 > 0)
            {
                p.push(maxChoc / 2);
            }

            // Decrement the time unit
            A--;
        }

        return ans;
    }
};

// Driver code to test both approaches
int main()
{
    Solution solution;
    vector<int> B = {6, 5, 7, 8, 9}; // Example input
    int A = 5;                       // Number of units of time

    // Test Approach 1
    cout << "Chocolates eaten using loop approach: " << solution.nchocWithLoop(A, B) << endl;

    // Test Approach 2
    cout << "Chocolates eaten using optimized approach: " << solution.nchocOptimized(A, B) << endl;

    return 0;
}
