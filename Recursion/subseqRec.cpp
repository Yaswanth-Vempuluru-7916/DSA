#include<bits/stdc++.h>
using namespace std;

void printSubseq( vector<int>v,int n,int index, vector<int>output, vector<vector<int>>&ans){
    if(index>=n){
        ans.push_back(output);
        return;
    }

    //Include

    printSubseq(v,n,index+1,output,ans);
    output.push_back(v[index]);
    printSubseq(v,n,index+1,output,ans);

    //Exclude

    // output.pop_back();

}

int main(){

    int n;
cout<<"Enter n : ";
    cin>>n;
    cout<<"\nEnter the elements :"<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"Now Printing the subsequences of the array : \n";
    vector<int>output;
    vector<vector<int>>ans;
    int index=0;
    printSubseq(v,n,index,output,ans);

    for(auto it = ans.begin();it!=ans.end();it++){
        for(auto elem = it->begin();elem!=it->end();elem++){
            cout<<*elem<<" ";
        }
        cout<<endl;
    }
}