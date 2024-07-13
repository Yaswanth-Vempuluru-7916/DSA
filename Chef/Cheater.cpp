#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="It is better to live your own destiny imperfectly than to   imitation  perfection.";
    // cin>>s;
    int count = 0;
    istringstream  mystream(s);
    string word;
    while(mystream>>word){
        cout<<word.length()<<" ";
        if(word.length()%2==0){
            count++;
        }
    }
    cout<<endl;
    float res = log2f(count);
    if(ceil(res)==floor(res)){
        cout<<"Cheater"<<endl;
    }else{
        cout<<"GG"<<endl;
    }
}