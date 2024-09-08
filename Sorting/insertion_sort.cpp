#include <bits/stdc++.h>
using namespace std;

void insertion(vector<int> &arr, int n)
{
   for(int i=0;i<n;i++){
    int j = i;

    while(j>0 && arr[j] < arr[j-1]){
        swap(arr[j] ,arr[j-1]);
        j--;
    }
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
    insertion(arr, arr.size());

    cout << "\nAfter Sorting : " << endl;

    for (auto elem : arr)
    {
        cout << elem << " ";
    }

    return 0;
}