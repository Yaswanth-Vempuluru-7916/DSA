#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

void subseq_with_k_sum(vector<int>& v, int n, vector<int>& output, int ind, int sum, int k) {
    if (ind == n) {
        if (sum == k) {
            for (auto it : output) cout << it << " ";
            cout << endl;
        }
        return;
    }

    // Include the current element
    output.push_back(v[ind]);
    sum+=v[ind];
    subseq_with_k_sum(v, n, output, ind + 1, sum , k);

    // Exclude the current element
    sum-=v[ind];
    output.pop_back();
    subseq_with_k_sum(v, n, output, ind + 1, sum, k);
}


bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Iterate over all subsets
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;

        // Check for each element if it is included in the subset
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += a[j];  // Add element a[j] to sum if it's in the subset
            }
        }

        // If the sum of the subset equals k, return true
        if (sum == k) {
            return true;
        }
    }

    // No subset found with sum k
    return false;
}



int main(){

        vector<int>v = {-1,5,-2,4,6,1};
        int n = v.size();
        int k =4;
        vector<int>output;

        subseq_with_k_sum(v,n,output,0,0,k);


return 0;

}

