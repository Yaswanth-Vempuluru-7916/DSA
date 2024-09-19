#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, farthest = 0, jumps = 0;

        while (r < n - 1) {
            farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,4,1,1,0,2,5};
    int result = sol.jump(nums);
    cout << "Minimum jumps: " << result << endl;

    return 0;
}
