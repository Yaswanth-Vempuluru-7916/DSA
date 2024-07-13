#include <bits/stdc++.h>
using namespace std;
#include <vector>
int main()
{
    vector<int> v{3,5,8,9};
    int n = v.size();
    // cin >> n;

    // for(int i=0;i<n;i++){
    //     int ele;
    //     cin>>ele;
    //     v.push_back(ele);
    // }

    vector<vector<int>>ans;

    for(int i = 0;i<n;i++){
        vector<int>subarr;
        for(int j=i;j<n;j++){
            subarr.push_back(v[j]);
            ans.push_back(subarr);
        }
    }

    for(auto i : ans){
       
        for(auto it = i.begin();it!=i.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }


}