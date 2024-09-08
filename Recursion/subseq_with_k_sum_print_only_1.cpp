#include <iostream>
#include <vector>
using namespace std;

bool subseq_with_k_sum(vector<int>& v, int n, vector<int>& output, int ind, int sum, int k) {
    
    if (ind == n) {
        if (sum == k) {
            for (auto it : output) cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    // Include the current element
    output.push_back(v[ind]);
    sum += v[ind];
    if (subseq_with_k_sum(v, n, output, ind + 1, sum, k)) {
        return true;
    }

    // Exclude the current element
    sum -= v[ind];
    output.pop_back();
    if (subseq_with_k_sum(v, n, output, ind + 1, sum, k)) {
        return true;
    }

    return false;
}

int main() {
    vector<int> v = {-1, 5, -2, 4, 6, 1 ,0,0};
    int n = v.size();
    int k = 4;
    vector<int> output;

    if (subseq_with_k_sum(v, n, output, 0, 0, k)) {
        cout << "Subseq found" << endl;
    } else {
        cout << "No Subseq found" << endl;
    }

    return 0;
}
