#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m,sum=0;
	    cin>>n>>m;
	    vector<int>bat,bow;
	    for(int i=0;i<n;i++){
	        int ele;
	        cin>>ele;
	        bat.push_back(ele);
	    }
	    for(int i=0;i<m;i++){
	        int ele;
	        cin>>ele;
	        bow.push_back(ele);
	    }
	    
	    if(n<4 || m<4 || (n+m)<11){
	        cout<<"-1"<<endl;
	    }else{
	        
	    sort(bat.begin(),bat.end(),greater<int>());
	    sort(bow.begin(),bow.end(),greater<int>());
	    int i,j;
	    for(i=0;i<4;i++){
	        sum+=bat[i];
	        
	    }
	    for(j=0;i<4;j++){
	        sum+=bow[j];
	    }

        int rem=3;
	    
	    while(i<n && j<m && rem){
	        if(bat[i]<=bow[j]){
	            sum+=bow[j];
	            j++;
	        }else{
	            sum+=bat[i];
	            i++;
	        }
	        rem--;
	    }
	    
	    while(i<n && rem){
	        sum+=bat[i];
	        rem--;
	    }
	    while(j<m && rem){
	        sum+=bow[j];
	        rem--;
	    }
	    
	    cout<<sum<<endl;
	    }
	    
	  
	   
	    }
	    
	}

