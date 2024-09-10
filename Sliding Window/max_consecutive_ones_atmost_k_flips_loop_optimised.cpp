#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0, zeros = 0;
        int l = 0, r = 0, n = nums.size();

        while (r < n) {
            if (nums[r] == 0) {
                zeros++;
            }

            if (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }
            if(zeros<=k){

            maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }

        return maxlen;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}; // Example input
    int k = 2; // Maximum number of 0s to flip
    int result = solution.longestOnes(nums, k);
    
    cout << "The longest subarray with at most " << k << " zeros flipped is: " << result << endl;
    return 0;
}
