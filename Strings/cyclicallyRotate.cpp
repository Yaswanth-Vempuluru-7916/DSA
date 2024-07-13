#include<iostream>
#include<string>
using namespace std;

// void isCyclicRotation(string &p, string &q) 
// {

//     if(p.size()!=q.size()){
//         return;
//     }
  
  
// }

int main(){

    string p="abacd",q="acdab";

    // if(isCyclicRotation(p,q)){
    //     cout<<"Yes"<<endl;
    // }else{
    //     cout<<"No"<<endl;
    // }
     int n = p.size();

    for(int k = 0;k<n;k++){
        string s=p;
        for(int i=0;i!=n;i++){
            s[i]=p[(i+k)%n];
        }
        cout<<s<<endl;
        
    }

    


        


return 0;

}