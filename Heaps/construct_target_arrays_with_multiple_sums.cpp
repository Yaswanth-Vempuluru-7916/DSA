#include <bits/stdc++.h>
using namespace std;
/* 
Time Complexity (TC):
- The time complexity is dominated by the while loop, where in each iteration we are pushing and popping an element from the max-heap. 
- Since heap operations (push and pop) take O(log n) time and we perform these operations at most O(n) times, where n is the number of elements in the target array.
- Thus, the overall time complexity is O(n log n), where n is the size of the target array.

Space Complexity (SC):
- We use a max-heap that stores all elements of the target array, which takes O(n) space.
- Additionally, there are a few extra variables that use constant space.
- Therefore, the overall space complexity is O(n), where n is the size of the target array.
*/
class Solution {
public:
    // Function to determine if the target array can be reduced to an array of all ones.
    bool isPossible(vector<int>& target) {
        // Max-heap to always get the largest element in the array.
        priority_queue<int> p(target.begin(), target.end());
        
        long long sum = 0, rem_sum = 0, maxi = 0, elem = 0;

        // Calculate the total sum of the array.
        for(auto elem : target){
            sum += elem;
        }
        
        // Keep reducing the largest element until the top of the heap becomes 1.
        while(p.top() != 1){
            maxi = p.top(); // Get the largest element
            p.pop();
            
            rem_sum = sum - maxi; // Sum of the rest of the array
            
            // Case 1: If the remaining sum is zero or larger than or equal to the largest element,
            // it's impossible to achieve the array of all ones.
            if(rem_sum <= 0 || rem_sum >= maxi) return false;

            // Find the remainder after dividing the largest element by the remaining sum.
            elem = maxi % rem_sum;
            
            // Case 2: If the remainder is 0 and the remaining sum is not 1, 
            // it's impossible to achieve the array of all ones.
            if(elem == 0) {
                if(rem_sum != 1)
                    return false;
                return true;
            }
            
            // Push the remainder back into the heap.
            p.push(elem);
            
            // Update the sum with the new element and the remaining sum.
            sum = elem + rem_sum;
        }

        // Case 3: If the largest element becomes 1, return true.
        return true;
    }
};

// Main function for testing the Solution class.
int main() {
    Solution sol;
    
    // Example 1: Target array [9, 3, 5] can be reduced to all ones.
    vector<int> target1 = {9, 3, 5};
    cout << "Example 1: Target = [9, 3, 5], Is Possible: " << sol.isPossible(target1) << endl; 
    // Output: true

    // Example 2: Target array [1, 1, 1, 2] cannot be reduced to all ones.
    vector<int> target2 = {1, 1, 1, 2};
    cout << "Example 2: Target = [1, 1, 1, 2], Is Possible: " << sol.isPossible(target2) << endl;
    // Output: false
    
    // Example 3: Target array [8, 5] can be reduced to all ones.
    vector<int> target3 = {8, 5};
    cout << "Example 3: Target = [8, 5], Is Possible: " << sol.isPossible(target3) << endl;
    // Output: true

    // Example 4: Target array [9, 3] cannot be reduced to all ones.
    vector<int> target4 = {9, 3};
    cout << "Example 4: Target = [9, 3], Is Possible: " << sol.isPossible(target4) << endl;
    // Output: false

    return 0;
}



/* Example Case Breakdown:
1. [9, 3, 5]:
   Initial max element is 9, sum of rest = 8. We can replace 9 with 9 % 8 = 1. Final array: [1, 3, 5].
   Max element is now 5, sum of rest = 4. Replace 5 with 5 % 4 = 1. Final array: [1, 3, 1].
   Max element is 3, sum of rest = 2. Replace 3 with 3 % 2 = 1. Final array: [1, 1, 1].
   All elements are 1. Thus, it's possible.

2. [1, 1, 1, 2]:
   Max element is 2, sum of rest = 3. Remaining sum >= max element, hence it's impossible.

3. [8, 5]:
   Max element is 8, sum of rest = 5. Replace 8 with 8 % 5 = 3. Final array: [3, 5].
   Max element is 5, sum of rest = 3. Replace 5 with 5 % 3 = 2. Final array: [2, 3].
   Max element is 3, sum of rest = 2. Replace 3 with 3 % 2 = 1. Final array: [1, 2].
   Max element is 2, sum of rest = 1. Replace 2 with 2 % 1 = 1. Final array: [1, 1].
   All elements are 1. Thus, it's possible.

4. [9, 3]:
   Max element is 9, sum of rest = 3. Remaining sum >= max element, hence it's impossible.
*/
