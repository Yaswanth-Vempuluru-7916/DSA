#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
1. const int &a (Constant Reference)
    • Explanation: This is a reference to an integer ( int ) that is constant, meaning
        that the value referred to by a cannot be modified. However, the reference
        itself allows us to avoid copying the integer.
    • Usage: This is often used to avoid copying large or complex data types (even
        though integers are small, this approach scales well with larger types) and
        ensures that the referenced value is not accidentally modified.
*/
void func(const int &a) {
    // You can read the value of 'a', but cannot modify it
    // a = 10; // Error: cannot modify a constant reference
    // a=11;
    cout << a << endl;
}

int main()
{

  int a = 10;
  func(a);
}
/*
1. const int (Constant Reference)
Description: This is a reference to a constant integer. The reference a does
not store a new copy of the integer but rather refers to an existing variable.
The const ensures that the value being referred to cannot be modified.
Usage: Often used to pass variables to functions without making a copy,
improving performance, especially for large data types (though not much for
small types like int ). It allows the function to read the value without
modifying it.
*/
void funcc(const int &a) {
    // 'a' is a reference to an existing integer; it cannot be modified.
    // a = 10; // Error: cannot assign to a 'const' reference
    cout << a << endl;
}

int main() {
    int x = 5;
    funcc(x);  // Passes 'x' by reference, not copying it
}

/*
2. const int a (Constant Value)
• Description: This is a constant integer. The variable a holds a copy of the
value passed to it, and the const ensures that its value cannot be changed
after it's initialized.
• Usage: Typically used when you need a local copy of a value in a function or
scope that should remain unchanged during its lifetime.
*/

void funccc(const int a) {
    // 'a' is a copy of the argument; it cannot be modified.
    // a = 10; // Error: 'a' is const and cannot be modified
    cout << a << endl;
}

int main() {
    int x = 5;
    funccc(x);  // Passes a copy of 'x'
}
