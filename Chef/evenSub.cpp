#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
// long long count(vector<vector<long long>>&ans){
//     long long even=0;
//     bool isEven = 0;
//     for(const auto& sub :ans){
//         for(const long long& element : sub){
//             if(element%2 ==0){
//                 isEven = true;
//             }
//         }
//         if(isEven){
//             even++;
//             isEven=false;
//         }
//     }

//     return even;
// }

long long countSubarrays(vector<long long> v) {
    long long even = 0;
    vector<vector<long long>> ans;

    for (long long i = 0; i < v.size(); i++) {
        vector<long long> sub;
        for (long long j = i; j < v.size(); j++) {
            sub.push_back(v[j]);  // Fixed the index to v[j]
            even += (v[j] % 2 == 0);  // Increment even if element is even
        }
        ans.push_back(sub);
    }

    return even;
}

// long long countSubarrays(vector<long long>v){
//     long long even=0;
//     bool isEven = 0;
//     vector<vector<long long>>ans;
//     for(long long i = 0;i<v.size();i++){
//         vector<long long>sub;
//         for(long long j=i;j<v.size();j++){
//            sub.push_back(v[i]);
//         }
//         ans.push_back(sub);          
        
//     }


    
//     return count(ans);
// }


int main(){

         long long n;
         cin>>n;
        vector<long long>v;
        for(long long i = 0;i<n;i++){
            int ele;
            cin>>ele;
            v.push_back(ele);
        }
        
        cout<<countSubarrays(v);


return 0;

}