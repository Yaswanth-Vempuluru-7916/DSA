#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive Approach (without memoization)
    int robRecursive(vector<int>& nums, int index) {
        if (index == 0) return nums[index];
        if (index < 0) return 0;

        int pick = nums[index] + robRecursive(nums, index - 2);
        int not_pick = robRecursive(nums, index - 1);

        return max(pick, not_pick);
    }

    // Memoization Approach (top-down dynamic programming)
    int robMemoization(vector<int>& nums, int index, vector<int>& dp) {
        if (index == 0) return nums[index];
        if (index < 0) return 0;

        if (dp[index] != -1) return dp[index];

        int pick = nums[index] + robMemoization(nums, index - 2, dp);
        int not_pick = robMemoization(nums, index - 1, dp);

        return dp[index] = max(pick, not_pick);
    }

    // Tabulation Approach (bottom-up dynamic programming)
    int robTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i > 1) {
                pick += dp[i - 2];
            }
            int not_pick = dp[i - 1];
            dp[i] = max(pick, not_pick);
        }

        return dp[n - 1];
    }

    // Space Optimization Approach (only storing the last two results)
    int robSpaceOptimized(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prev = nums[0];  // dp[i-1]
        int prev2 = 0;       // dp[i-2]

        for (int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int not_pick = prev;
            int cur = max(pick, not_pick);
            prev2 = prev;
            prev = cur;
        }

        return prev;
    }

    // Function to test all methods
    void testRobMethods(vector<int>& nums) {
        int n = nums.size();
        cout << "House values: ";
        for (int val : nums) cout << val << " ";
        cout << endl;

        // Recursive Approach
        cout << "Recursive Approach: " << robRecursive(nums, n - 1) << endl;

        // Memoization Approach
        vector<int> dp(n, -1);
        cout << "Memoization Approach: " << robMemoization(nums, n - 1, dp) << endl;

        // Tabulation Approach
        cout << "Tabulation Approach: " << robTabulation(nums) << endl;

        // Space Optimization Approach
        cout << "Space Optimized Approach: " << robSpaceOptimized(nums) << endl;
    }
};

int main() {
    Solution solution;

    // Example input: values of houses
    vector<int> nums = {2, 7, 9, 3, 1 ,15 ,17};

    // Test all methods
    solution.testRobMethods(nums);

    return 0;
}
