#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, string>> vec = {{3, "apple"}, {1, "banana"}, {2, "cherry"}};

    // Sort vector of pairs based on the first element
    sort(vec.begin(), vec.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first < b.first;  // Compare keys
    });

    // Print sorted vector
    for (const auto& pair : vec) {
        cout << pair.first << ": " << pair.second << endl;
    }

            // After Sorting : 
            // 1: banana
            // 2: cherry
            // 3: apple

    return 0;
}
