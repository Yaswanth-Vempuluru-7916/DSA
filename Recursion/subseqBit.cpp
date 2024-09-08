#include <bits/stdc++.h>
using namespace std;

//!Bit Manipulation (i & (1 << j)):
//?Instead of using num & 1 and then shifting num right (num >>= 1), the more standard way to check if the j-th bit is set in i is i & (1 << j). This eliminates the need to shift num and makes the code more straightforward.
//?Vector Initialization: You don't need the variable num. The check for each bit can be done directly using i & (1 << j) inside the loop.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        // Iterate over all possible subsets (2^n possibilities)
        for (int i = 0; i < (1 << n); i++) {
            vector<int> output;
            
            // For each number, check if the j-th bit is set
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    output.push_back(nums[j]);
                }
            }
            ans.push_back(output);  // Add current subset to answer
        }
        
        return ans;
    }
};


int main()
{

    int n;
    cout << "Enter n : ";
    cin >> n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=0;i<(1<<n);i++){

       int num = i;

       for(int j=0;j<n;j++){
            if(num&1){
                cout<<v[j]<<" ";
            }
            num>>=1;
       }

       cout<<endl;
    }


    return 0;
}