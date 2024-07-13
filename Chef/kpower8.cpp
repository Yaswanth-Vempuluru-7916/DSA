#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,pro=1,twos=0;
	    bool flag = 0;
	    double res;
	    cin>>n;
	    vector<int>v;
	    for(int i=0;i<n;i++){
	        int ele;
	        cin>>ele;
	        v.push_back(ele);
	    }
	    
	    for(int i=0;i<n;i++){
	        pro = pro*v[i];
	        if(v[i]==2){
	            twos++;
	        }
	    }
	    
	    if(twos%8==0 && pro!=1){
	       cout<<"YES"<<endl;
	        
	    }else if(pro==1){
	       cout<<"YES"<<endl;
	    }else{
	        
	        cout<<"NO"<<endl;
	    }
	   
	   //for(int k=1;pow(k,8)<=pro;k++){
	       
	   // if(pow(k,8)==pro){
	   //     flag=1;
	   //     break;
	   // }
	    
	   //}
	   
	   //if(flag){
	   //    cout<<"YES"<<endl;
	   //}else{
	   //    cout<<"NO"<<endl;
	       
	   //}
	   
	   //if (isKPower8(pro)) {
	   //    cout<<"YES"<<endl;
        
    // } else {
        
	   //    cout<<"NO"<<endl;
    // }
	
}
}
// // #include <bits/stdc++.h>
// // using namespace std;

// // int main() {
// // 	int t;
// // 	cin>>t;
// // 	while(t--){
// // 	    int n,pro=1;
// // 	    double res;
// // 	    cin>>n;
// // 	    vector<int>v;
// // 	    for(int i=0;i<n;i++){
// // 	        int ele;
// // 	        cin>>ele;
// // 	        v.push_back(ele);
// // 	    }
	    
// // 	    for(int i=0;i<n;i++){
// // 	        pro = pro*v[i];
// // 	    }
	    
// // 	    if(pro==1){
// // 	        cout<<"YES"<<endl;
// // 	    }
// // 	    res = log2(pro);
// // 	    if(floor(res)==res && int(res)%8==0){
// // 	        cout<<"YES"<<endl;
// // 	    }else{
// // 	        cout<<"NO"<<endl;
// // 	    }
	    
// // 	}
// // }
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    int n,pro=1;
// 	    bool flag = 0;
// 	    double res;
// 	    cin>>n;
// 	    vector<int>v;
// 	    for(int i=0;i<n;i++){
// 	        int ele;
// 	        cin>>ele;
// 	        v.push_back(ele);
// 	    }
	    
// 	    for(int i=0;i<n;i++){
// 	        pro = pro*v[i];
// 	    }
	    
	   
// 	   for(int k=1;pow(k,8)<=pro;k++){
	       
// 	    if(pow(k,8)==pro){
// 	        flag=1;
// 	        break;
// 	    }
	    
// 	   }
	   
// 	   if(flag){
// 	       cout<<"YES"<<endl;
// 	   }else{
// 	       cout<<"NO"<<endl;
	       
// 	   }
// 	}
// }
