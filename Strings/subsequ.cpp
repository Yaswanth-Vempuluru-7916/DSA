// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstring> // Include <cstring> for strlen
// using namespace std;

// void solve(vector<string>& ans, const char* input, string& output, int index) {
//     if (index >= std::strlen(input)) { // Qualify strlen with std::
//         ans.push_back(output);
//         return;
//     }

//     solve(ans, input, output, index + 1);
//     output.push_back(input[index]);
//     solve(ans, input, output, index + 1);
// }

// void printSubsequences(const char* input) {
//     vector<string> ans;
//     string output;
//     int index = 0;
//     solve(ans, input, output, index);

//     for (const auto& sub : ans) {
//         cout << sub << endl;
//     }
// }

// int main() {
//     char input[] = "Hello";
//     printSubsequences(input);
//     return 0;
// }
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

void solve(vector<string>& ans, const char* input, string& output, int index) {
    if (index >= strlen(input)) {
        if (!output.empty()) {  // Check if output is not empty
            ans.push_back(output);
        }
        return;
    }

    solve(ans, input, output, index + 1);  // Exclude the current character
    output.push_back(input[index]);
    solve(ans, input, output, index + 1);  // Include the current character
    output.pop_back();  // Backtrack
}

void printSubsequences(const char* input) {
    vector<string> ans;
    string output;
    int index = 0;
    solve(ans, input, output, index);

    for (const auto& sub : ans) {
        cout << sub << endl;
    }
}

int main() {
    char input[] = "Hello";
    printSubsequences(input);
    return 0;
}
