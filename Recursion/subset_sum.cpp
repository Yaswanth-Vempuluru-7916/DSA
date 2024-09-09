#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute subset sums
void solve(vector<int>& arr, int index, int n, int sum, vector<int>& ans) {
    if (index == n) {
        ans.push_back(sum);
        return;
    }
    
    // Include the current element
    solve(arr, index + 1, n, sum + arr[index], ans);
    // Exclude the current element
    solve(arr, index + 1, n, sum, ans);
}

// Function to generate all subset sums
vector<int> subsetSums(vector<int> arr, int n) {
    int sum = 0;
    int index = 0;
    vector<int> ans;
    solve(arr, index, n, sum, ans);
    return ans;
}

// Main function
int main() {
    // Example input
    vector<int> arr = {10,22,4,6,4,9};
    int n = arr.size();
    
    // Compute subset sums
    vector<int> result = subsetSums(arr, n);
    
    sort(result.begin(), result.end());
    // Output the result
    cout << "Subset sums are: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
