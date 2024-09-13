#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 1. Recursive Approach (without memoization) for circular houses
    int robRecursive(vector<int>& nums, int index) {
        if (index == 0) return nums[index];
        if (index < 0) return 0;

        int pick = nums[index] + robRecursive(nums, index - 2);
        int not_pick = robRecursive(nums, index - 1);

        return max(pick, not_pick);
    }

    // Helper function to handle non-circular array for recursion
    int robRecursiveCircular(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> firstExclude(nums.begin() + 1, nums.end());
        vector<int> lastExclude(nums.begin(), nums.end() - 1);

        return max(robRecursive(firstExclude, firstExclude.size() - 1),
                   robRecursive(lastExclude, lastExclude.size() - 1));
    }

    // 2. Memoization Approach (top-down dynamic programming) for circular houses
    int robMemoization(vector<int>& nums, int index, vector<int>& dp) {
        if (index == 0) return nums[index];
        if (index < 0) return 0;

        if (dp[index] != -1) return dp[index];

        int pick = nums[index] + robMemoization(nums, index - 2, dp);
        int not_pick = robMemoization(nums, index - 1, dp);

        return dp[index] = max(pick, not_pick);
    }

    // Helper function to handle non-circular array for memoization
    int robMemoizationCircular(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> firstExclude(nums.begin() + 1, nums.end());
        vector<int> lastExclude(nums.begin(), nums.end() - 1);

        vector<int> dp1(firstExclude.size(), -1);
        vector<int> dp2(lastExclude.size(), -1);

        return max(robMemoization(firstExclude, firstExclude.size() - 1, dp1),
                   robMemoization(lastExclude, lastExclude.size() - 1, dp2));
    }

    // 3. Tabulation Approach (bottom-up dynamic programming) for circular houses
    int robTabulation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n, 0);
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

    // Helper function to handle non-circular array for tabulation
    int robTabulationCircular(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> firstExclude(nums.begin() + 1, nums.end());
        vector<int> lastExclude(nums.begin(), nums.end() - 1);

        return max(robTabulation(firstExclude),
                   robTabulation(lastExclude));
    }

    // 4. Space Optimization Approach (only storing the last two results) for circular houses
    int robSpaceOptimized(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prev2 = 0;
        int prev = nums[0];

        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i > 1) {
                pick += prev2;
            }
            int not_pick = prev;
            int curr = max(pick, not_pick);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    // Helper function to handle non-circular array for space optimization
    int robSpaceOptimizedCircular(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> firstExclude(nums.begin() + 1, nums.end());
        vector<int> lastExclude(nums.begin(), nums.end() - 1);

        return max(robSpaceOptimized(firstExclude),
                   robSpaceOptimized(lastExclude));
    }

    // Function to test all methods
    void testRobCircularMethods(vector<int>& nums) {
        int n = nums.size();
        cout << "House values: ";
        for (int val : nums) cout << val << " ";
        cout << endl;

        // Recursive Approach
        cout << "Recursive Approach (Circular): " << robRecursiveCircular(nums) << endl;

        // Memoization Approach
        cout << "Memoization Approach (Circular): " << robMemoizationCircular(nums) << endl;

        // Tabulation Approach
        cout << "Tabulation Approach (Circular): " << robTabulationCircular(nums) << endl;

        // Space Optimization Approach
        cout << "Space Optimized Approach (Circular): " << robSpaceOptimizedCircular(nums) << endl;
    }
};

int main() {
    Solution solution;

    // Example input: values of houses
    vector<int> nums = {2, 3, 2};  // Circular houses example

    // Test all circular methods
    solution.testRobCircularMethods(nums);

    return 0;
}
