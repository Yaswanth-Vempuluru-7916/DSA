#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the pivot where the rotation happens
    int findPivot(vector<int>& nums) {
        int n = nums.size();

        // If array is not rotated
        if (n == 0 || nums[0] < nums[n-1]) {
            return -1;
        }

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return i;
            }
        }
        return -1;
    }

    // Standard binary search implementation
    int binarySearch(vector<int>& nums, int target, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1;
    }

    // Main function to search for target in rotated sorted array
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);

        // Case 1: If no rotation (or array not rotated), just do binary search
        if (pivot == -1) {
            return binarySearch(nums, target, 0, nums.size() - 1);
        }

        // Case 2: Search in the left part before the pivot
        int left = binarySearch(nums, target, 0, pivot);

        // Case 3: Search in the right part after the pivot
        if (left == -1) {
            return binarySearch(nums, target, pivot + 1, nums.size() - 1);
        }

        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};  // Rotated sorted array
    int target = 0;  // Target to search

    int result = sol.search(nums, target);

    if (result != -1) {
        cout << "Target " << target << " found at index: " << result << endl;
    } else {
        cout << "Target " << target << " not found" << endl;
    }

    return 0;
}
