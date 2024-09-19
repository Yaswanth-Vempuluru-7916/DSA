#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n) 
// Space Complexity: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;

        for(int i=0; i<nums.size(); i++) {
            if(i > maxi) return false;
            maxi = max(maxi, i + nums[i]);
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,1,1,0,2,5};
    bool result = sol.canJump(nums);
    cout << (result ? "Can jump" : "Cannot jump") << endl;

    return 0;
}
