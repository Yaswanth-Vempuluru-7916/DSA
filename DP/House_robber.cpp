#include <bits/stdc++.h>
using namespace std;
long long int space(vector<int> &nums,int start,int end){
    int n = nums.size();


    long long int prev2 = nums[start];
   long long int  prev1 = max(static_cast<long long int>(nums[start+1]),prev2);

    for(int i=start+2;i<=end;i++){
        long long int incl = prev2 + nums[i];
        long long int excl = prev1 ;
        long long int ans = max(incl,excl);
        prev2 = prev1;
        prev1 = ans;
    }
 return prev1;
}
long long int houseRobber(vector<int> &valueInHouse) {
  int n = valueInHouse.size();
  if(n==0){
      return 0;
  }

  if(n==1){
      return valueInHouse[0];
  }
  // vector<int> first, second;


  // for (int i = 0; i < n; i++) {
  //   if (i != n - 1) {
  //     first.push_back(valueInHouse[i]);
  //   }
  //   if (i != 0) {
  //     second.push_back(valueInHouse[i]);
  //   }
  // }

  // return max(space(first),space(second));
  return max(space(valueInHouse,0,n-2),space(valueInHouse,1,n-1));

}