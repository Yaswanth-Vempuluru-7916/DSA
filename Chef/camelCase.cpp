// CPP program to convert given sentence 
/// to camel case. 
#include <bits/stdc++.h> 
using namespace std; 

// Function to remove spaces and convert 
// into camel case 
string convert(string str) 
{ 
	int i=0;
	while(true){
		i=0;
		while(i<str.size()){
			if(str[i]==' '){
			str[i+1] = toupper(str[i+1]);
            cout<<i<<endl;
			str.erase(i,1);
			
			break;
			}
			i++;
		}
		
		if(i==str.size()){break;}
	}

return str;
} 

// Driver program 
int main() 
{ 
	string str = "I get intern at geeksforgeeks"; 
	cout << convert(str); 
	return 0; 
} 
