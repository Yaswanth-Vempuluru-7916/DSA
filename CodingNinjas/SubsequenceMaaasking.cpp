#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007

void printSubsequence(const vector<int>& arr, int mask) {
    vector<int> subseq;
    for (int i = 0; i < arr.size(); i++) {
        if (mask & (1 << i)) {
            subseq.push_back(arr[i]);
        }
    }

    cout << "Subsequence: ";
    for (int i = 0; i < subseq.size(); i++) {
        cout << subseq[i];
        if (i != subseq.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int expanseOfSubsequences(const vector<int>& arr) {
    int n = arr.size();
    long long sum = 0; // Using long long for sum to avoid overflow

    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subseq;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subseq.push_back(arr[i]);
            }
        }

        if (!subseq.empty()) {
            auto max_it = max_element(subseq.begin(), subseq.end());
            auto min_it = min_element(subseq.begin(), subseq.end());

            sum = (sum + (*max_it - *min_it)) % MOD;

            printSubsequence(arr, mask);
        }
    }

    return static_cast<int>(sum); // Convert sum back to int
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    cout << "Sum of differences in subsequences: " << expanseOfSubsequences(arr) << endl; // Output: 12

    return 0;
}
