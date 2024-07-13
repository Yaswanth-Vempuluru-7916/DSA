#include <bits/stdc++.h> 
using namespace std;
 char comp(int a,int b){
       if(a<b){
           return '<';
       }else if(a>b){
           return '>';
       }else{
           return '=';
       }
   }
void longestDangerousRange(vector<int>& height, int n)
{   
    vector<char>sym(n);
  
    int j=0;
   for(int i=0;i<n-1;i++){
       sym[j++]=comp(height[i],height[i+1]);
   }

    for(auto nums:sym){
        cout<<nums<<" ";
    }
    cout<<endl;

    int maxi = INT_MIN;
    int cnt=1;

    for(int i = 0;i<sym.size()-1;i++){
        if(sym[i]=='<' && sym[i+1]=='>' || sym[i]=='>' && sym[i+1]=='<'){
            cnt++;
        }else{
            maxi = max(cnt,maxi);
            cnt=1;
        }
    }
cout<<maxi<<endl;
}
int main(){

vector<int>height={2,8};
// vector<int>height={9, 4 ,2 ,10 ,7, 8, 8, 1, 9};
longestDangerousRange(height,height.size());
        


return 0;

}