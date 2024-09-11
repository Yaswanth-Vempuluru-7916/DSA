#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int a=-1,b=-1,c=-1,mini=INT_MAX;
        int r=0,n=s.size();

        while (r < n) {
           if(s[r]=='a') a=r;
           if(s[r]=='b') b=r;
           if(s[r]=='c') c=r;

           if(a>=0 &&b>=0&&c>=0){
                mini = min(a,min(b,c));
                cnt+=mini+1;
           }
            r++;
        }

        return cnt;
    }
};


int main() {
    Solution solution;
    
    // Example input
    string s = "abcabc";
    
    int result = solution.numberOfSubstrings(s);
    
    cout << "The number of substrings containing 'a', 'b', and 'c' is: " << result << endl;
    
    return 0;
}
