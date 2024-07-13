#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
#include <bits/stdc++.h> 
void minimumRotations(int n, string s)
{
	
    int k;

	for(int i =0;i<s.size();i++){
		string str;
		k=1;
		for(int j=0;j<n;j++){
			str[j]=str[(j+k)%n];
			k++;
		}
        cout<<str<<endl;
		if(str == s){
			return;
		}

	}
	return;
}
int main(){

        string s = "ninja";
        // string s = "ccccc";

minimumRotations(s.size(),s);
return 0;

}