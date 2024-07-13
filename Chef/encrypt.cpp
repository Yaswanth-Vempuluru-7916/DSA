#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<int>v;
	    for(int i = 0;i<n;i++){
	        int ele;
	        cin>>ele;
	        v.push_back(ele);
	    }
	    
	    sort(v.begin(),v.end());
	    int s = 0,ele,add,mul,maxi;
	    
	    for(int i = 0;i<n;i++){
	        ele = v[i];
	        add = s+ele;
	        mul = s*ele;
	        maxi = max(add,mul);
	        s=maxi;
	        
	        
	    }
	    
	    cout<<s%MOD<<endl;
	}

}
