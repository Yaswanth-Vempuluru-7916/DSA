#include <iostream>
using namespace std;
int solve(int *arr, int n, int sum)
{
    if(n==0){
        return sum;
    }

    sum = sum+arr[n-1];
    return solve(arr,n-1,sum);
}
int main()
{

    int arr[] = {1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    sum = solve(arr, size, sum);
    cout<<sum<<endl;
    return 0;
}