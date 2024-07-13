#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void solve(vector<string>&ans,string str,string output,int index){
    if(index>=str.size()){
        ans.push_back(output);
        return;
    }
    solve(ans,str,output,index+1);
    //include
    output.push_back(str[index]);
    solve(ans,str,output,index+1);
}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string a,b;
        cin>>a;
        cin>>b;
        string output;
        int index = 0;
        vector<string>ans;

    solve(ans,b,output,index);

    // for(auto i : ans){
    //     cout<<i<<endl;
    // }
string temp="";
int len=0;
    for(int i=0;i<a.size();i++){
        temp+=a[i];
        
        auto it = find(ans.begin(),ans.end(),temp);

        if(it!=ans.end()){
            if(temp.size()!=0){

            len = temp.size();
            }else{
                len=0;
            }
        }
    }

    cout<<len<<endl;


    }
        

return 0;

}