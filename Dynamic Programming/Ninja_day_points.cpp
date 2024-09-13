#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    // Method 1: Recursive Approach
    int solveRecursive(int day, int last, vector<vector<int>> &arr)
    {
        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < arr[0].size(); task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }

        int maxi = 0;
        for (int task = 0; task < arr[0].size(); task++)
        {
            if (task != last)
            {
                int points = arr[day][task] + solveRecursive(day - 1, task, arr);
                maxi = max(maxi, points);
            }
        }

        return maxi;
    }

    // Method 2: Memoization Approach
    int solveMemoization(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < arr[0].size(); task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }

        if (dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;
        for (int task = 0; task < arr[0].size(); task++)
        {
            if (task != last)
            {
                int points = arr[day][task] + solveMemoization(day - 1, task, arr, dp);
                maxi = max(maxi, points);
            }
        }

        return dp[day][last] = maxi;
    }

    // Method 3: Tabulation Approach (Bottom-Up DP)
    int solveTabulation(vector<vector<int>> &arr, int n)
    {
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base case for day 0
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});

        // Fill dp table
        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                dp[day][last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int points = arr[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], points);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }

    // Method 4: Space Optimized Approach (Bottom-Up DP)
    int solveSpaceOptimized(vector<vector<int>> &arr, int n)
    {
        vector<int> prev(4, 0);

        // Base case for day 0
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max({arr[0][0], arr[0][1], arr[0][2]});

        // Fill the dp array
        for (int day = 1; day < n; day++)
        {
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++)
            {
                temp[last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int points = arr[day][task] + prev[task];
                        temp[last] = max(temp[last], points);
                    }
                }
            }
            prev = temp;
        }

        return prev[3];
    }

    // Wrapper to call any of the methods
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        // Method 1: Recursive
        // return solveRecursive(n-1, 3, arr);

        // Method 2: Memoization
        // vector<vector<int>> dp(n, vector<int>(4, -1));
        // return solveMemoization(n-1, 3, arr, dp);

        // Method 3: Tabulation
        // return solveTabulation(arr, n);

        // Method 4: Space Optimized
        return solveSpaceOptimized(arr, n);
    }
};

int main()
{
    // Create an instance of Solution
    Solution sol;

    // Input: 2D vector representing points for each task on each day
    vector<vector<int>> points = {
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6},
        {8, 3, 7}};

    int n = points.size();

    // Call the function and print the result
    cout << "Maximum Points: " << sol.maximumPoints(points, n) << endl;

    return 0;
}