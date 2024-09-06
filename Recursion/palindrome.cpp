#include<bits/stdc++.h>
using namespace std;
bool isPal(string str,int i,int n){

        if(i>=n/2){
            return true;
        }
        if(str[i]!=str[n-i-1]){
            return false;
        }

        return isPal(str,i+1,n);
}
int main(){

        // string str = "madam";
        string str = "Katherine enirehtaK";

        if(isPal(str,0,str.size())){
            cout<<"Palindrome"<<endl;
        }else{
            cout<<"Not Palindrome"<<endl;

        }


return 0;

}