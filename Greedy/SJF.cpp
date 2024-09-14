#include <iostream>
#include <vector>
#include <algorithm> // for sort

// Time Complexity: O(n log n)
// Explanation: Sorting the burst times takes O(n log n), and iterating through the burst times
// to calculate the waiting time takes O(n). Therefore, the overall time complexity is O(n log n).

// Space Complexity: O(1)
// Explanation: The space used is constant (O(1)) because we are only using a few additional 
// variables (`totalWaitTime` and `accumulatedTime`) independent of the input size.

using namespace std;

class Solution {
public:
    long long solve(vector<int>& burstTimes) {
        sort(burstTimes.begin(), burstTimes.end()); // Sort burst times for SJF

        long long wait = 0; // Total waiting time
        long long time = 0; // Accumulated waiting time for processes

        // Calculate total waiting time
        for (int i = 0; i < burstTimes.size() - 1; i++) {
            time += burstTimes[i]; // Accumulate the time of each process
            wait += time; // Add it to the total wait time
        }

        // Return average waiting time
        return wait / burstTimes.size();
    }
};

int main() {
    Solution solution;

    // Example burst times for processes
    vector<int> burstTimes = {4,3,7,1,2};

    // Call the SJF solver function and print the result
    cout << "Average Waiting Time: " << solution.solve(burstTimes) << endl;

    return 0;
}
