#include <iostream>
#include <vector>
#include <algorithm> // For sort()

using namespace std;
/*In the given code, the base case is implicitly handled by the design of the solve function. Let's break it down to clarify why there is no explicit base case like if(index == n) return; and why it's still valid.

Recursive Structure Explanation:
Recursive Call Structure:

The function recursively explores all elements in the array starting from the index.
For each element, the algorithm either includes it in the current subset or skips it.
Implicit Base Case:

The base case here is when index reaches n, which automatically happens when the loop finishes.
The loop condition (for (int i = index; i < n; i++)) ensures that once the index reaches n, there are no more elements left to process, so no further recursive calls are made.
At every call of the solve function, the current subset is added to ans (ans.push_back(output)), meaning the subsets are being recorded as we recursively build them.
Why No Explicit Base Case:

The recursive function doesn't need an explicit base case like if (index == n) return; because:
The loop naturally terminates once index >= n.
At the end of each recursive path, when the function backtracks to remove the last element, the loop exits without making any more recursive calls.
The function handles all subsets up to the final index automatically, ensuring completeness without requiring an explicit return condition.
The Flow:
Start at index = 0 and consider all elements.
For each element, two choices are made:
Either include the element and recursively proceed.
Or skip the element and recursively proceed to the next.
When the loop exhausts all elements (i.e., when index reaches n), the recursion naturally terminates.
Base Case in Other Implementations:
In some recursive problems, like generating permutations or combinations, you often see an explicit base case such as if (index == n) return;. This explicit return is needed when you are working on each element one at a time and need to signal when all elements have been processed.

However, in this problem:

The loop structure handles the termination condition.
The current subset is recorded every time the function is called, which makes the function automatically cover all cases without needing an explicit base case.
Example Walkthrough:
For nums = [1, 2, 2], the recursive calls proceed as follows:

Start with an empty output subset.
For i = 0, add 1, then explore subsets starting from i + 1.
For i = 1, add 2, then explore subsets starting from i + 2.
For i = 2, add another 2, then explore subsets starting from i + 3 (no further elements).
Backtrack by removing the last 2, and explore the path where you skip it.
Continue until all subsets are covered.
At each step, the loop ensures you move through the elements, and the recursion ends naturally when no more elements are left.

Thus, the code doesn't need an explicit base case because the recursive process is controlled by the loop itself, and the function handles all subsets correctly without it.

so if the base case i==n is present then we may lose the subsets in the each level but we will get only the last level right?


Yes, exactly! If you add an explicit base case like if (i == n) return;, you may lose subsets generated at intermediate levels. Here's why:

What Happens if You Add if (i == n) return;:
If you add a base case like if (i == n) return; at the start of the solve function, you would immediately return from the recursion when the index reaches n without processing or storing the intermediate subsets at each level. This will result in only subsets from the final level being recorded, and you'll miss out on all the subsets that should have been built recursively.

Why Only the Last Level Subsets Get Recorded:
Let's break down what happens if you add if (i == n) return;:

Subset Generation Process:
The recursion is supposed to generate subsets by gradually adding elements at each level and then either proceeding further or backtracking.
If if (i == n) return; Is Added:
The moment i == n, the function would return without adding the current subset to the result (ans).
Since the recursive call is made for every subset, the intermediate subsets (those built while backtracking and moving up the recursion tree) will not be added to ans.
You would only capture subsets that exist in the last recursive level (where the index reaches n), but miss all the intermediate combinations.
Example:
For nums = [1, 2], if you add if (i == n) return;, here's what will happen:

Without Base Case: The function will correctly generate:

[]
[1]
[1, 2]
[2]
With if (i == n) return;:

Once i == n, the function will return, and you won't get the subsets at intermediate levels.
You would only get the subsets at the very last level (where all elements have been processed), which would likely be [1, 2] and possibly an empty subset depending on how the rest of the code is structured.
Why the Original Code Works Without It:
The recursive function handles the entire tree of possibilities naturally:

At every step, the current subset (output) is recorded.
As you explore each branch, you either add or remove elements, and every time the function backtracks, you generate new subsets from earlier levels.
Thus, not having the base case if (i == n) return; ensures that subsets at all levels (not just the deepest one) are included.
*/


class Solution {
public:
    // Recursive function to generate subsets
    void solve(vector<int>& nums, int index, int n, vector<int>& output, vector<vector<int>>& ans) {
        // Add the current subset (output) to the result (ans)
        ans.push_back(output);

        // Loop through the remaining elements starting from 'index'
        for (int i = index; i < n; i++) {
            // Skip duplicate elements to avoid duplicate subsets
            if (i > index && nums[i - 1] == nums[i]) {
                continue;
            }

            // Include the current element in the subset
            output.push_back(nums[i]);

            // Recursively explore further subsets starting from the next element
            solve(nums, i + 1, n, output, ans);

            // Backtrack: Remove the last added element to explore other subsets
            output.pop_back();
        }
    }

    // Main function that finds all unique subsets
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> output;           // Temporary vector to store current subset
        vector<vector<int>> ans;      // To store all unique subsets
        int n = nums.size();          // Size of the input array

        // Sort the array to handle duplicates easily
        sort(nums.begin(), nums.end());

        // Call the recursive function starting from index 0
        solve(nums, 0, n, output, ans);

        return ans; // Return all the unique subsets
    }
};

// Main function to test the solution
int main() {
    Solution solution;  // Create an instance of the Solution class

    // Example input: a list of numbers with duplicates
    vector<int> nums = {1, 2, 2};

    // Get all unique subsets using the subsetsWithDup function
    vector<vector<int>> result = solution.subsetsWithDup(nums);

    // Output the subsets
    cout << "Unique subsets are:" << endl;
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
