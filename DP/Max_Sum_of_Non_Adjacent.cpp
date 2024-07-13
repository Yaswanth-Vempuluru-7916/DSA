#include <bits/stdc++.h>
using namespace std;

// void solveRec(vector<int> &nums, int i, vector<int> &ans, int sum)
// {
//     if (i >=nums.size())
//     {
//         ans.push_back(sum);
//         return;
//     }

//     solveRec(nums, i + 2, ans, sum + nums[i]);
//     solveRec(nums, i + 1, ans, sum + 0);
// }

// int solveRec(vector<int> &nums,int n){
//     if(n<0){
//         return 0;
//     }

//     if(n==0){
//         return nums[0];
//     }

//     int incl = solveRec(nums,n-2)+nums[n];
//     cout<<"incl"<<incl<<endl;
//     int excl = solveRec(nums,n-1)+0;
//     cout<<"excl"<<excl<<endl;

//     return max(incl,excl);
// }

int Tabulate(vector<int> &nums)
{

    // int n = nums.size();
    // vector<int> dp(n, 0);
    // dp[0] = nums[0];

    // for (int i = 1; i < n; i++)
    // {
    //     int incl = dp[i - 2] + nums[i];
    //     int excl = dp[i - 1] + 0;
    //     dp[i] = max(incl, excl);
    // }

    // return dp[n - 1];

     int n = nums.size();
    if (n == 0) return 0; // Handle edge case of empty nums vector

    vector<int> dp(n, 0);
    dp[0] = max(0, nums[0]); // Initialize dp[0] with maximum of nums[0] and 0
    if (n == 1) return dp[0]; // Handle edge case of single element in nums vector

    dp[1] = max(dp[0], nums[1]); // Initialize dp[1] with maximum of nums[1] and dp[0]

    for (int i = 2; i < n; i++)
    {
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }

    return dp[n - 1];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // vector<int> ans;
    // int sum = 0;
    // int i = 0;
    // solveRec(nums, i, ans, sum);
    // for(auto it = ans.begin();it!=ans.end();it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;

    // int maxi = INT_MIN;
    // for(int i=0;i<ans.size();i++){
    //     maxi = max(ans[i],maxi);
    // }

    // return maxi;

    int n = nums.size();
    // vector<int>dp(n,-1);
    // return solveRec(nums,n-1);

    return Tabulate(nums);
}

int main()
{
    vector<int> nums = {9, 9, 8, 2, 9};
    cout << "The max non adjacent sum is " << maximumNonAdjacentSum(nums) << endl;
    // cout<<"The max non adjacent sum is "<<maximumNonAdjacentSum(nums)<<endl;
    return 0;
}