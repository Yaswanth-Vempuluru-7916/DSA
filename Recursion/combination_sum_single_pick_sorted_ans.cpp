#include <iostream>
#include <vector>
#include <algorithm>  // for sort()

using namespace std;

class Solution {
public:
    
    void solve(vector<int>& candidates, int index, int n, int target, vector<int>& output, vector<vector<int>>& ans) {
       
        if (target == 0) {
            ans.push_back(output);
            return;
        }

        // Iterate over the candidates starting from 'index'
        for (int i = index; i < n; i++) {
            // Skip duplicates to ensure unique combinations
            // We only skip duplicates after the first element, which is why 'i > index' is checked
            if (i > index && candidates[i - 1] == candidates[i]) {
                continue;
                //1 1 1 2 2
                //0 1 2 3 4
                // if i pick the 1st index and if i keep i>=index i will lose the other 1 i have to pick. So by default u pick the first index
            }

            // If the current candidate is greater than the remaining target, stop further processing
            // This works because the array is sorted, so no subsequent numbers will satisfy the condition
            if (candidates[i] > target) {
                break;
            }

            // Include the current candidate in the combination
            output.push_back(candidates[i]);

            // Recursively call solve with the next index, reducing the target by the value of the current candidate
            // Since we are not allowing reuse of the same element, we pass 'i + 1' to move to the next element
            solve(candidates, i + 1, n, target - candidates[i], output, ans);

            // Backtrack: Remove the last added candidate to explore other possibilities
            output.pop_back();
        }
    }

   
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;  
        vector<int> output; 
        sort(candidates.begin(), candidates.end());  
        int n = candidates.size();  

      
        solve(candidates, 0, n, target, output, ans);

        return ans;  
    }
};


int main() {
    Solution solution;  

   
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

   
    vector<vector<int>> result = solution.combinationSum2(candidates, target);

    
    cout << "Unique combinations that sum to " << target << " are:" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
