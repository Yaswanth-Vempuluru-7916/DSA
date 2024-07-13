#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;


int recursiveMem(int nStairs , vector<int>&dp){
    if(nStairs==0||nStairs==1){
        return 1;
    }

    if(dp[nStairs]!=-1){
        return dp[nStairs];
    }
    
    dp[nStairs]=recursiveMem(nStairs-1,dp)+recursiveMem(nStairs-2,dp);
    return dp[nStairs];
}

int Tabulate(int n){

    vector<int>dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n-1]+dp[n-2];


}

int memorization(int n){

    
    int prev2=1;
    int prev1 =1;

    for(int i=2;i<n;i++){
        int curr = prev1+prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1+prev2;


}

int countDistinctWays(int nStairs){
    //Step 1 : Cretae a dp array
    vector<int>dp(nStairs+1,-1);
    return recursiveMem(nStairs,dp);
    
}

int main(){

        int n;
        cout<<"Enter the no of stairs"<<endl;
        cin>>n;

        //  cout << "Distinct ways to climb " << n << " stairs: " <<countDistinctWays(n)<<endl;
        //  cout << "Tabulate Distinct ways to climb " << n << " stairs: " <<Tabulate(n)<<endl;
         cout << "Space Distinct ways to climb " << n << " stairs: " <<memorization(n)<<endl;


return 0;

}