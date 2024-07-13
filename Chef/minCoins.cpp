#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,x,y;
	    cin>>n>>x>>y;
	    vector<int>v;
	    for(int i=0;i<n;i++){
	        int ele;
	        cin>>ele;
	        v.push_back(ele);
	    }
	    
	    int normal ,master,mini,minCoins=0;
	    
	    for(int i = 0;i<n;i++){
	        normal = x*v[i];
	        master = y;
	       mini = min(normal,master);
	       minCoins+=mini;
	       
	    }
	    
	    cout<<minCoins<<endl;
	}

}
