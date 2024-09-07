#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, string>> vec = {{3, "apple"}, {1, "banana"}, {2, "cherry"}};

    // Sort vector of pairs based on the second element
    sort(vec.begin(), vec.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.second > b.second;  // Compare values
    });

    // Print sorted vector
    for (const auto& pair : vec) {
        cout << pair.first << ": " << pair.second << endl;
    }

        // 2: cherry
        // 1: banana
        // 3: apple
    return 0;
}
