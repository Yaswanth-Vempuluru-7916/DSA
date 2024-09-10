#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int l=0, r=0, n=s.size(), maxlen=-1;
        map<char,int> freq;
        
        while (r < n) {
            freq[s[r]]++;
            
            // Shrink the window if we have more than k distinct characters
            if (freq.size() > k) {
                freq[s[l]]--;
                if (freq[s[l]] == 0) {
                    freq.erase(s[l]);
                }
                l++;
            }
            
            // Check if the current window has exactly k distinct characters
            if (freq.size() == k) {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        
        return maxlen;
    }
};

int main() {
    Solution solution;
    
    // Example input
    string s = "aabacbebebe";
    int k = 3;
    
    int result = solution.longestKSubstr(s, k);
    if(result == -1)
        cout << "No valid substring found" << endl;
    else
        cout << "The longest substring with exactly " << k << " distinct characters is: " << result << endl;
    
    return 0;
}
