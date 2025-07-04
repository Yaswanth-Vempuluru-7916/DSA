#include <iostream>
#include <stack>
using namespace std;

int priority(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return -1;
}

int main() {
    stack<char> st;
    string str = "a+b*(c^d-e)";
    string ans = "";

    int i = 0;
    while (i < str.size()) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')) {
            ans += str[i]; // Operand, directly append
        } else if (str[i] == '(') {
            st.push(str[i]); // Push '(' to stack
        } else if (str[i] == ')') {
            // Pop until '(' is found
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Pop '('
        } else {
            // Ensure stack is not empty before checking top element
            while (!st.empty() && priority(st.top()) >= priority(str[i]) && str[i] != '^') {
                ans += st.top();
                st.pop();
            }
            st.push(str[i]); // Push current operator
        }
        i++;
    }

    // Pop remaining operators
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << "The infix to postfix conversion is: " << ans << endl;
    return 0;
}
