#include <iostream>
#include <vector>
using namespace std;
// bool find(int *arr, int n, int key)
// {
//     if (n == 0)
//     {
//         return false;
//     }

//     if(arr[n-1]==key){
//         return true;
//     }

//     return find(arr,n-1,key);
// }
bool find(int *arr, int n, int key)
{
    if (n == 0)
    {
        return false;
    }

    if(arr[0]==key){
        return true;
    }

    return find(arr+1,n-1,key);
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 161, 7, 8};
    int key = 161;
    int size = sizeof(arr) / sizeof(arr[0]);
    if (find(arr, size, key))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}