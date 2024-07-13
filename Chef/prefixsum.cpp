#include <iostream>
#include <unordered_map>
#include <vector>

int longestSubarrayWithSumK(const std::vector<int>& nums, int K) {
    int maxLength = 0;
    int sum = 0;
    std::unordered_map<int, int> prefixSum; // Map to store prefix sum and its index

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == K) {
            maxLength = i + 1; // Current subarray from index 0 to i has sum K
        } else if (prefixSum.find(sum - K) != prefixSum.end()) {
            // If there exists a prefix sum such that (sum - prefixSum) = K, update maxLength
            maxLength = std::max(maxLength, i - prefixSum[sum - K]);
        }

        // Store the index of the first occurrence of prefix sum
        if (prefixSum.find(sum) == prefixSum.end()) {
            prefixSum[sum] = i;
        }
    }

    return maxLength;
}

int main() {
    int N = 7;
    int K = 0;
    std::vector<int> nums = {-1 ,0 ,1, 1, -1, -1 ,0};

    int result = longestSubarrayWithSumK(nums, K);
    std::cout << "Length of longest subarray with sum " << K << " is " << result << std::endl;

    return 0;
}
