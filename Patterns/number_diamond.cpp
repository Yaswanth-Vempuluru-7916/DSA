#include<bits/stdc++.h>
using namespace std;

int main(){

        int n;cin>>n;

        for(int i=n-1;i>=0;i--){
            int j=0;
            for(;j<i;j++) cout<<" ";
            for(;j<n;j++) cout<<(n-j)<<" ";
            cout<<endl;
        }

return 0;

}