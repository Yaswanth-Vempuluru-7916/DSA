#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*

    TC : O(N) +O(N)  outer while and inner while
    SC : O(3)

*/
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int l=0, r=0, n=arr.size(), maxlen=0;
        map<int,int> freq;
        while (r < n) {
            freq[arr[r]]++;
            
            while (freq.size() > 2) {
                freq[arr[l]]--;
                if (freq[arr[l]] == 0) {
                    freq.erase(arr[l]);
                }
                l++;
            }
            
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        
        return maxlen;
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> fruits = {1, 2, 1, 2, 3, 3, 2, 1};  // Fruits type
    int result = solution.totalFruits(fruits);
    
    cout << "The maximum number of fruits that can be collected in two baskets is: " << result << endl;
    
    return 0;
}
