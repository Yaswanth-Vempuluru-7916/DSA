#include <iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

   bool cmp(pair<char,int>&a,pair<char,int>&b){
    return a.second>b.second;
}

int main()
{

    string s="aArgFfFAAa";
    map<char, int> mp;

    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }




    string ss;
	


    vector<pair<char,int>>A;

    for(auto &it : mp){
        A.push_back(it);
    }

    sort(A.begin(),A.end(),cmp);

    for(auto it = A.begin();it!=A.end();it++){
        int count = it->second;
        while(count--){
            ss+=it->first;
        }
    }

for (int i = 0; i < ss.size(); i++)
{
    cout<<ss[i];
}




    return 0;
}