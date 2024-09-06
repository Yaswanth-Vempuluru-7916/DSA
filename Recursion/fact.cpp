#include<iostream>
using namespace std;
long long fact(long long n){
    if(n<2){
        return 1;
    }

    return n*fact(n-1);
}
int main(){
    long long n;
    cout<<"Enter n : ";
    cin>>n;
    
    if (n > 20) {
        cout << "Factorial of " << n << " is too large for long long to handle." << endl;
        return 0;
    }

    cout << fact(n) << endl;
    return 0;
}
