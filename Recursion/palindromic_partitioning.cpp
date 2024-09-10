#include <bits/stdc++.h>
using namespace std;

/*  Time Complexity:
        • Recursive partitioning: The function explores all possible partitioning options,
          leading to O(2^n) recursive calls (since each character can either be included
          in the current partition or start a new partition).
        • Palindrome check: For each substring, the isPa1indrome() function takes
          O(n) time to check if it's a palindrome.
        • Thus, the overall time complexity is O(n * 2^n).

        Time Complexity: O( (2^n) *k*(n/2) )

        Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.


    Space Complexity:
        • The recursive stack can go as deep as O(n), and the space used for storing
          partitions and substrings is also O(n). Hence, the space complexity is O(n) in
          addition to the space for storing the final answer.

    Space Complexity: O(k * x)

        Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
*/

class Solution {
public:
    // Function to check if the substring is a palindrome
    bool isPalindrome(string str, int s, int e) {
        while (s <= e) {
            if (str[s++] != str[e--]) {
                return false;
            }
        }
        return true;
    }

    // Function to solve the partitioning problem
    void solve(string s, int index, int n, vector<string>& output,
               vector<vector<string>>& ans) 
    {
        // If index reaches the length of the string, add the current output to ans
        if (index == n) {
            ans.push_back(output);
            return;
        }

        for (int i = index; i < n; i++) {
            // Check if the substring from index to i is a palindrome
            if (isPalindrome(s, index, i)) {
                // Extract the palindrome substring and push it into the output
                output.push_back(s.substr(index, i - index + 1));
                // Recursively partition the remaining substring
                solve(s, i + 1, n, output, ans);
                // Backtrack and remove the last added substring
                output.pop_back();
            }
        }
    }

    // Main function to return all possible palindrome partitions
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        int n = s.size();
        solve(s, 0, n, output, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    string s = "aaabbb";
    vector<vector<string>> result = obj.partition(s);
    
    // Print the result
    for (const auto& partition : result) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
