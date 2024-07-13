#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(string& str,string output,int index,vector<string>&ans){

    if(index>=str.size()){
        ans.push_back(output);
        return;
    }

    solve(str,output,index+1,ans);
    char ch = str[index];
    output.push_back(ch);
    solve(str,output,index+1,ans);


}
vector<string>subsequence(string str){
    string output;
    vector<string>ans;
    int index = 0;

    solve(str,output,index,ans);
    return ans;
}
int main(){

        string str = "abc   ";
        vector<string>ans;

        ans = subsequence(str);

         for (const auto& sub : ans) {
        cout << sub << endl;
    }


return 0;

}