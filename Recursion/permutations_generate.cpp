#include <bits/stdc++.h>
#include <vector>
#include <algorithm>  // for sort()
using namespace std;


//! instead of map u can use bool array;

class Solution {
public:
    void solve(vector<int>& nums, int n, vector<int>& output,
               vector<vector<int>>& ans, unordered_map<int, bool>& mpp) 
    {
        // Base case: when the output size matches the input size, we have a valid permutation
        if (output.size() == n) {
            ans.push_back(output);
            return;
        }

        // Iterate through the array to generate permutations
        for (int i = 0; i < n; i++) {
            // Check if the current element is already used in the permutation
            if (!mpp[i]) {
                // Add the element to the current permutation
                output.push_back(nums[i]);
                mpp[i] = true; // Mark as used

                // Recursive call to generate further permutations
                solve(nums, n, output, ans, mpp);

                // Backtrack: remove the last element and mark it as unused
                output.pop_back();
                mpp[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool> mpp; // To track if an element is already used
        int n = nums.size();
        vector<int> output;  // To store the current permutation
        vector<vector<int>> ans;  // To store all the permutations

        // Initialize the map with all elements set to false (not used)
        for (int i = 0; i < n; i++) {
            mpp[i] = false;
        }

        // Start solving for the first permutation
        solve(nums, n, output, ans, mpp);

        return ans;
    }
};

int main() {
    Solution solution;  

   
    vector<int> nums = {10, 1, 2};
    

   
    vector<vector<int>> result = solution.permute(nums);

    
    cout << "Permutations are:" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
