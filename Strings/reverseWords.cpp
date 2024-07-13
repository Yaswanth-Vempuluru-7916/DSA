#include<iostream>
#include <sstream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

string reverseString(string &str){
	  
        stringstream ss(str);
        vector<string>ans;
        string child;
        while(ss>>child){
            ans.push_back(child);
            
        }
    string s;
	for(int i=ans.size()-1;i>=0;i--){
		s+=ans[i]+" ";
	}

	return s;
}

// int main(){

//         string parentString = "welcome to Coding Ninjas";
//         stringstream s(parentString);
//         stack<string>ans;
//         string child;
//         while(s>>child){
//             ans.push(child);
//             ans.push(" ");
//         }
//     ans.pop();
//     string answer="";
//     while(!ans.empty()){
//         answer.append(ans.top());
//         ans.pop();
//     }
// cout<<answer<<endl;
// return 0;

// }