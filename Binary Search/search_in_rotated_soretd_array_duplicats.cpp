#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Binary search in rotated sorted array with duplicates
    bool binarySearch(vector<int>& nums, int target, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return true;  // Target found
            }

            // If duplicates are found at start, mid, and end, increment s and decrement e
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
                continue;// Skip the rest of the code and go to the next iteration
            }

            // Left half is sorted
            if (nums[s] <= nums[mid]) {
                // Check if target is within the left half range
                if (nums[s] <= target && target <= nums[mid]) {
                    e = mid - 1;  // Search in the left half
                } else {
                    s = mid + 1;  // Search in the right half
                }
            }
            // Right half is sorted
            else {
                // Check if target is within the right half range
                if (nums[mid] <= target && target <= nums[e]) {
                    s = mid + 1;  // Search in the right half
                } else {
                    e = mid - 1;  // Search in the left half
                }
            }
        }

        return false;  // Target not found
    }

    // Main search function
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};  // Rotated sorted array with duplicates
    int target = 0;  // Target to search

    bool result = sol.search(nums, target);

    if (result) {
        cout << "Target " << target << " found in the array." << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}
