#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int index, int target, vector<int>& output, vector<vector<int>>& ans) {
        // Base case: if the target is zero, a valid combination is found
        if (target == 0) {
            ans.push_back(output);
            return;
        }
        // If index is out of bounds or target is negative, return
        if (index >= candidates.size() || target < 0) {
            return;
        }

        // Option 1: Include the current candidate
        if (target >= candidates[index]) {
            output.push_back(candidates[index]);
            solve(candidates, index, target - candidates[index], output, ans);
            output.pop_back(); // Remove the candidate for backtracking
        }

        // Option 2: Skip the current candidate
        solve(candidates, index + 1, target, output, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> output;
        vector<vector<int>> ans;
        solve(candidates, 0, target, output, ans); // Start the recursion
        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> candidates = {2, 6, 7,1};
    int target = 7;

    // Get the combinations
    vector<vector<int>> result = solution.combinationSum(candidates, target);

    // Output the results
    cout << "Combinations that sum to " << target << " are:" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
