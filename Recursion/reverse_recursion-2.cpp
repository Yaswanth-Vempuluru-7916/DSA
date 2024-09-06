#include <bits/stdc++.h>
using namespace std;

// normal int type arrays are passed by reference but vector<int> pased by value;

void reverse(vector<int>& arr, int low , int high)
{
    if (low>=high)
    {
        return;
    }
    swap(arr[low], arr[high]);
    reverse(arr, low+1,high-1);
}

void print(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> arr{1, 6, 8, 4, 3, 12, 4, 5, 4, 2};
    int n = arr.size();
    cout << "Before Reversing: ";
    print(arr, n);
    reverse(arr, 0, n-1);
    cout << "After Reversing: ";
    print(arr, n);

    return 0;
}
