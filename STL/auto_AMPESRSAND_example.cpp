#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    vector<int> vec = {1, 2, 3}; // 2 4 6
    for (auto &elem : vec)
    {
        elem *= 2; // Modifies the actual elements in the vector
    }
    for (auto elem : vec)
        cout << elem << " ";
    cout << endl;
    vector<int> vecc = {1, 2, 3}; // 1 2 3
    for (auto elem : vecc)
    {
        elem *= 2; // doesnt  Modify the actual elements in the vector
    }
    for (auto elem : vecc)
        cout << elem << " ";
    cout << endl;
}
