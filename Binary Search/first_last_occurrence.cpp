#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int mid, lb = nums.size(), ub = nums.size();

        // Lower Bound
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (nums[mid] >= target) {
                lb = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        s = 0, e = nums.size() - 1;


        // Upper Bound
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (nums[mid] > target) {
                ub = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        if (lb == nums.size() || nums[lb] != target) {
            return {-1, -1};
        }

        return {lb, ub - 1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);

    cout << "Target " << target << " found at range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
