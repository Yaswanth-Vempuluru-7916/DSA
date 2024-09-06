#include <bits/stdc++.h>
using namespace std;

// Recursive Fibonacci
int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Memoized Recursive Fibonacci (Top-down Dynamic Programming)
int fibonacciMemoized(vector<int>& dp, int n) {
    if (n <= 1) {
        return n;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = fibonacciMemoized(dp, n - 1) + fibonacciMemoized(dp, n - 2);
    return dp[n];
}

// Fibonacci using Tabulation (Bottom-up Dynamic Programming)
int fibonacciTabulation(vector<int>& dp, int n) {
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Fibonacci using Space Optimization
int fibonacciSpaceOptimized(int n) {
    int prev2 = 0, prev = 1, cur;
    if (n == 0) return prev2;
    for (int i = 2; i <= n; i++) {
        cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main() {
    int n = 10;
    
    // Recursive Fibonacci
    cout << "Fibonacci using Recursion: " << fibonacciRecursive(n) << endl;
    
    // Memoized Fibonacci
    vector<int> dp(n + 1, -1);
    cout << "Fibonacci using Memoization: " << fibonacciMemoized(dp, n) << endl;
    
    // Tabulation Fibonacci
    cout << "Fibonacci using Tabulation: " << fibonacciTabulation(dp, n) << endl;
    
    // Space Optimized Fibonacci
    cout << "Fibonacci using Space Optimization: " << fibonacciSpaceOptimized(n) << endl;

    return 0;
}
