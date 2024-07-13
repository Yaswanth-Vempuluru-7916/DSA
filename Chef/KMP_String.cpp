#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> computeLPS(const string& pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(const string& text, const string& pattern) {
    vector<int> lps = computeLPS(pattern);
    vector<int> indices;
    int m = pattern.size();
    int n = text.size();
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            indices.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return indices;
}

int main() {
    string text = "abaxbcaxbxaxbcxabxcabc";
    string pattern = "abc";
    vector<int> indices = KMP(text, pattern);
    if (!indices.empty()) {
        cout << "Pattern found at indices:";
        for (int index : indices) {
            cout << " " << index;
        }
        cout << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }
    return 0;
}
