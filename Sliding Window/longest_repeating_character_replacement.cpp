#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxfreq = 0, maxlen = 0, n = s.size();
        vector<int> hash(26, 0);
        
        while (r < n) {
            hash[s[r] - 'A']++;
            maxfreq = max(maxfreq, hash[s[r] - 'A']);
            
            if ((r - l + 1) - maxfreq > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        
        return maxlen;
    }
};

int main() {
    Solution solution;
    
    string s;
    int k;
    
    cout << "Enter the string (consisting of uppercase English letters): ";
    cin >> s;
    
    cout << "Enter the value of k (number of replacements allowed): ";
    cin >> k;
    
    int result = solution.characterReplacement(s, k);
    cout << "The length of the longest substring after at most " << k << " replacements: " << result << endl;
    
    return 0;
}







