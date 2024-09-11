#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSubstrings_Optimised(string s) {
        int cnt = 0;
        int l = 0, r = 0, n = s.size();
        int freq[3] = {0};  // Use an array instead of map, as we only have 'a', 'b', 'c'
        
        while (r < n) {
            freq[s[r] - 'a']++;  // Increment the count of the current character
            
            // Check if all three characters ('a', 'b', 'c') are present in the current window
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // All substrings from l to the end of the string are valid
                cnt += (n - r);
                
                // Shrink the window from the left
                freq[s[l] - 'a']--;
                l++;
            }
            
            r++;
        }

        return cnt;
    }

     int numberOfSubstrings(string s) {
        int cnt = 0;
        int l = 0, r = 0, n = s.size();
        map<char, int> freq;

        while (r < n) {
            freq[s[r]]++;
            
            // Check if all three characters ('a', 'b', 'c') are present in the current window
            while (freq.size() == 3) {
                // All substrings from l to the end of the string are valid
                cnt += (n - r);
                
                // Shrink the window from the left
                freq[s[l]]--;
                if (freq[s[l]] == 0) {
                    freq.erase(s[l]);
                }
                l++;
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
