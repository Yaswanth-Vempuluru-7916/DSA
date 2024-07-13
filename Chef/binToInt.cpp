#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int binaryToInt(string str){
    int j=0,ans=0;
    for(int i=str.size()-1;i>=0;i--){
        ans= ans+((str[i]-'0')*pow(2,j));
        j++;
    }

    return ans;
}
int main(){

        string str ="110";

    cout<<binaryToInt(str)<<endl;

return 0;

}