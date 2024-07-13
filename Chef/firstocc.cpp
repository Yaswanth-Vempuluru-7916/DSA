#include<iostream>
using namespace std;

int main(){

        string a = "abcxbc";
        string b = "abcxbc";

        for(int i=0;i<=b.size();i++){
            string temp = b.substr(i,a.size());
            cout<<temp<<endl;
            if(temp==a){
                cout<<i<<endl;
            }
        }


return 0;

}