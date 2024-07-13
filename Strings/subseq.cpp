#include<iostream>
using namespace std;

void subsequence(string str){
    for(int i = 0;i<str.size();i++){
        string ans="";
        for(int j=i;j<str.size();j++){
            ans+=str[j];
            cout<<ans<<endl;
        }
    }
}

int main(){

        string str="aabc";
        subsequence(str);


return 0;

}