#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Memoization approach
    int solveMemo(int n, int cnt, vector<int>& dp) {
        if (cnt > n) {
            return 0;
        }
        if (cnt == n) {
            return 1;
        }
        if (dp[cnt] != -1) {
            return dp[cnt];
        }
        return dp[cnt] = solveMemo(n, cnt + 1, dp) + solveMemo(n, cnt + 2, dp);
    }

    int climbStairsMemo(int n) {
        vector<int> dp(n + 1, -1);
        return solveMemo(n, 0, dp);
    }

    // Tabulation approach (bottom-up dynamic programming)
    int climbStairsTabulation(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // Space Optimization approach (only storing the last two results)
    int climbStairsOptimized(int n) {
        if (n == 1) return 1;
        int prev2 = 1;  // equivalent to dp[i-2]
        int prev1 = 1;  // equivalent to dp[i-1]

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter the number of stairs: ";
    cin >> n;

    // Using Memoization
    cout << "Memoization result: " << solution.climbStairsMemo(n) << endl;

    // Using Tabulation
    cout << "Tabulation result: " << solution.climbStairsTabulation(n) << endl;

    // Using Space Optimization
    cout << "Space Optimized result: " << solution.climbStairsOptimized(n) << endl;

    return 0;
}
