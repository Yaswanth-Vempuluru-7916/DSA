#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
!• Time Complexity: O(n x n!)
    • The function generates all possible permutations, which is n!, and for
each permutation, the elements are pushed to the result, which takes
O(n) time.

!• Space Complexity: O(n!)
    • The recursive call stack uses space proportional to the depth of recursion
(which is O(n)) and the space required to store all permutations is
O(n!).

*/
class Solution {
public:
    // Recursive function to generate permutations
    void solve(vector<int>& nums, int index, int n, vector<vector<int>>& ans) {
        // Base case: If index reaches the size of nums, add the current permutation
        if (index == n) {
            ans.push_back(nums);
            return;
        }

        // Generate permutations by swapping elements
        for (int i = index; i < n; i++) {
            swap(nums[index], nums[i]);  // Swap the current element with element at index i
            solve(nums, index + 1, n, ans);  // Recursively solve for the next index
            swap(nums[index], nums[i]);  // Backtrack by swapping elements back
        }
    }

    // Function to start the permutation generation process
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        int n = nums.size();  // Size of the input array
        vector<vector<int>> ans;  // To store the result of permutations

        solve(nums, index, n, ans);  // Start solving from index 0
        return ans;
    }
};

// Main function to test the permutation function
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};  // Input array for which we want to generate permutations

    vector<vector<int>> result = sol.permute(nums);  // Call the permute function

    // Output the generated permutations
    cout << "Permutations of the array are: " << endl;
    for (const auto& perm : result) {
        cout << "[ ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
