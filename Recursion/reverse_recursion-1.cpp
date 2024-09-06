#include<bits/stdc++.h>
using namespace std;

// normal int type arrays are passed by reference but vector<int> pased by value;

void reverse(vector<int>arr , int n , int i){
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    reverse(arr,n,i+1);
}

void print(vector<int>arr ,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){

       vector<int>arr{1,6,8,4,3,12,4,5,4,2};
        int n = arr.size();
        cout<<"Before Reversing: ";
    print(arr,n);
    reverse(arr,n,0);
        cout<<"After Reversing: ";
    print(arr,n);


return 0;

}






















// #include<iostream>
// using namespace std;

// void reverse(int *arr , int n , int i){
//     if(i>=n/2){
//         return;
//     }
//     swap(arr[i],arr[n-i-1]);
//     reverse(arr,n,i+1);
// }

// void print(int *arr ,int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }
// int main(){

//         int arr[]={1,6,8,4,3,12,4,5,4,2};
//         int n = sizeof(arr)/sizeof(int);
//         cout<<"Before Reversing: ";
//     print(arr,n);
//     reverse(arr,n,0);
//         cout<<"After Reversing: ";
//     print(arr,n);


// return 0;

// }