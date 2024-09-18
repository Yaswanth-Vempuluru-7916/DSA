#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the smallest range that includes at least one element from each of the k lists
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Initialize a priority queue (min-heap) to store elements of the form {value, {list_index, element_index}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;

        int maxi = INT_MIN, mini = INT_MAX;
        // Initialize the heap with the first element of each list
        for (int i = 0; i < nums.size(); i++) {
            p.push({nums[i][0], {i, 0}});
            maxi = max(maxi, nums[i][0]);
            mini = min(mini, nums[i][0]);
        }

        // Store the initial range as the current answer
        pair<int, int> ans = {mini, maxi};

        while (p.size() == nums.size()) {
            auto minPair = p.top();
            p.pop();

            int i = minPair.second.first, j = minPair.second.second;
            mini = minPair.first;  // Update mini with the new minimum

            // Check if this new range is smaller
            if ((maxi - mini) < (ans.second - ans.first)) {
                ans = {mini, maxi};
            }

            // Move to the next element in the same list if possible
            if (j + 1 < nums[i].size()) {
                int nextValue = nums[i][j + 1];
                p.push({nextValue, {i, j + 1}});
                maxi = max(maxi, nextValue);  // Update maxi with the new value
            } else {
                break;  // If we can't add more elements from one of the lists, break the loop
            }
        }

        return {ans.first, ans.second};  // Return the smallest range
    }



     vector<int> My_smallestRange_code(vector<vector<int>>& nums) {
        vector<pair<int, pair<int, int>>> temp;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i][0]);
            mini = min(mini, nums[i][0]);
            temp.push_back({nums[i][0], {i, 0}});
        }

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            p(temp.begin(), temp.end());

        pair<int, int> ans{mini, maxi};

        pair<int, pair<int, int>> min_pairr;
        int i, j, data;

        while (p.size() == nums.size()) {
            min_pairr = p.top();
            i = min_pairr.second.first;
            j = min_pairr.second.second;
            p.pop();

            if (j + 1 < nums[i].size()) {
                maxi = max(maxi, nums[i][j + 1]);
                p.push({nums[i][j + 1], {i, j + 1}});
            }

            if (p.size() != nums.size()) {
                return {ans.first, ans.second};
            }
            min_pairr = p.top();
            data = min_pairr.first;
            mini = data;

            if ((ans.second - ans.first) > (maxi - mini)) {
                ans.first = mini;
                ans.second = maxi;
            } 
            //! Not required
            // else if ((ans.second - ans.first) == (maxi - mini)) {
            //     if (ans.first > mini) {
            //         ans.first = mini;
            //         ans.second = maxi;
            //     }
            // }
        }

        return {ans.first, ans.second};
    }
};

// Main function for testing
int main() {
    Solution sol;
    vector<vector<int>> nums = {{4, 10, 15, 24, 26},
                                {0, 9, 12, 20},
                                {5,18,22,30}};
    vector<int> result = sol.smallestRange(nums);
    cout << "Smallest range is: [" << result[0] << ", " << result[1] << "]\n";
    return 0;
}

/*
Time Complexity (TC): O(n * log k)
- We iterate through the lists, where 'n' is the total number of elements (sum of elements in all lists).
- Each push and pop operation on the priority queue takes O(log k), where 'k' is the number of lists.

Space Complexity (SC): O(k)
- The space complexity is dominated by the priority queue, which holds at most 'k' elements at a time, where 'k' is the number of lists.
*/
