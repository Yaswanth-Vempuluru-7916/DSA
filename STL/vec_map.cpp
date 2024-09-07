#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    vector<map<int, string>> vec = {{{1, "apple"}, {2, "banana"}}, {{3, "cherry"}, {4, "date"}}};

    // Iterator over the vector of maps
    for (auto vecIt = vec.begin(); vecIt != vec.end(); ++vecIt) {
        // Iterator over each map inside the vector
        for (auto mapIt = vecIt->begin(); mapIt != vecIt->end(); ++mapIt) {
            cout << "Key: " << mapIt->first << " Value: " << mapIt->second << endl;
        }
        cout << endl;
    }

    return 0;
}
