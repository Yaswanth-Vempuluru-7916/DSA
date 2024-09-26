#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Time Complexity: O(n log n) due to sorting both arrival and departure times
// Space Complexity: O(1) excluding the input space, since we only use a few extra variables
class Solution {
  public:
    // Function to find the minimum number of platforms required at the railway station
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int cnt = 0, maxcnt = 0;
        
        // Sort the arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0;
        
        // Iterate over the trains
        while (i < arr.size()) {
            if (arr[i] <= dep[j]) {
                // If a train is arriving before or at the same time a train departs
                cnt++;
                i++;
            } else {
                // If a train departs before the next one arrives
                cnt--;
                j++;
            }
            maxcnt = max(maxcnt, cnt);
        }
        return maxcnt;  // Maximum platforms needed at any time
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Example test case
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    // Call the function to find the minimum number of platforms
    int result = sol.findPlatform(arr, dep);

    // Output the result
    cout << "Minimum number of platforms required: " << result << endl;

    return 0;
}
