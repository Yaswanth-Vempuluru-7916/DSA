#include <bits/stdc++.h>
#include <string>

using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        //Calculate the factorial till n
        //4! = 24 
        //then 4 , 3! groups will be formed
        //4! = 4 * 3!
        vector<int>nums;
        for(int i=1;i<n;i++){
            fact = fact*i;
            nums.push_back(i);
        }

        //Adding the last number
        nums.push_back(n);

        //since we have decided on 0 based indexing 
        k = k-1;
        string ans = "";
        while(true){
            ans+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+(k/fact));
            if(nums.size()==0){
                break;
            }
            k = k%fact;
            fact = fact/nums.size();
        }

        return ans;
    }
};
int main() {
    Solution sol;
    int n, k;
    
    // Test input
    cout << "Enter n and k: ";
    cin >> n >> k;
    
    string result = sol.getPermutation(n, k);
    
    cout << "The " << k << "-th permutation of the set [1.." << n << "] is: " << result << endl;

    return 0;
}
