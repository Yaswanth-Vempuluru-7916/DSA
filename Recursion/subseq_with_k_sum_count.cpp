#include <iostream>
#include <vector>
using namespace std;

void subseq_with_k_sum(vector<int> &v, int n, vector<int> &output, int ind, int sum, int k, int &count)
{
    if (ind == n)
    {
        if (sum == k)
        {
            count++;
        }
        return;
    }

    // Include the current element
    output.push_back(v[ind]);
    sum += v[ind];
    subseq_with_k_sum(v, n, output, ind + 1, sum, k, count);

    // Exclude the current element
    sum -= v[ind];
    output.pop_back();
    subseq_with_k_sum(v, n, output, ind + 1, sum, k, count);
}

int IMP_PATTERN_subseq_with_k_sum(vector<int> &v, int n,  int ind, int sum, int k)
{


    //* if array contains only positives

    if(sum>k){
        return 0;
    }
    if (ind == n)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    // Include the current element
    sum += v[ind];

   //!!! VVIMP PATTERN FOR DP
    int left = IMP_PATTERN_subseq_with_k_sum(v, n, ind + 1, sum, k);

    // Exclude the current element
    sum -= v[ind];
    
   //!!! VVIMP PATTERN FOR DP
    int right = IMP_PATTERN_subseq_with_k_sum(v, n,  ind + 1, sum, k);

    return left + right;
}

int main()
{

    vector<int> v = {-1, 5, -2, 4, 6, 1, 0, 0};
    int n = v.size();
    int k = 4;
    vector<int> output;
    // int count = 0;
    // subseq_with_k_sum(v, n, output, 0, 0, k, count);

    // cout << "Count is : " << count << endl;
    cout << "Count is : " << IMP_PATTERN_subseq_with_k_sum(v,n,0,0,k) << endl;

    return 0;
}
