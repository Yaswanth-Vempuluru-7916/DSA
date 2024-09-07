#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, string>> vec = {{1, "apple"}, {2, "banana"}};

    // Iterate over the vector using a range-based for loop
    for (auto p : vec) {
        cout << "Key: " << p.first << " Value: " << p.second << endl;
    }

    // Or using an iterator
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << "Key: " << it->first << " Value: " << it->second << endl;
    }

    return 0;
}
