#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int> &arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        bool swapped = false;

        for (int j = 0; j < i; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }

        cout << "Pass : "<<n-i<< endl;
    }
}

int main()
{

    vector<int> arr{1, 53, 82, 701, 5, 1010, 53, 198, 54, 2, 41, 63};
    cout << "Before Sorting : " << endl;

    for (auto elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;
    bubble(arr, arr.size());

    cout << "\nAfter Sorting : " << endl;

    for (auto elem : arr)
    {
        cout << elem << " ";
    }

    return 0;
}