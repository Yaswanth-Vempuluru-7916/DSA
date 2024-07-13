#include <bits/stdc++.h>
using namespace std;

long long minmin(vector<long long> v, long long n, long long k)
{
    long long diff = 0;
    for (long long i = 0; i < n - 1; i++)
    {
        diff += abs(v[i] - v[i + 1]);
    }
    return diff;
}

int main()
{

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v;
        long long initialsum=INT_MIN;
        for (long long i = 0; i < n; i++)
        {
            long long ele;
            cin >> ele;
            v.push_back(ele);
        }
       initialsum = minmin(v, n, k);

        for (long long i = 0; i < n; i++)
        {
            long long org = v[i];
            v[i] = 1;

            long long sum = minmin(v, n, k);
            initialsum = max(initialsum, sum);

            v[i] = k;
            sum = minmin(v, n, k);
            initialsum = max(initialsum, sum);
            v[i] = org;
        }

        cout << initialsum << endl;
    }
}

// cout<<"max "<<maxval<<" "<<maxInd<<endl;
// cout<<"min "<<minval<<" "<<minInd<<endl;
// int temp = v[minInd];
// v[minInd]=1;

//  for(int i=0;i<n-1;i++){
//     diffmin+=abs(v[i]-v[i+1]);
// }

// cout<<"diffmin "<<diffmin<<endl;

// cout<<"minarray "<<endl;
// for(int i=0;i<n;i++){
//     cout<<v[i]<< " ";
// }
// cout<<endl;

// v[minInd]=temp;
// temp = v[maxInd] ;
// v[maxInd]=k;

//  cout<<"maxarray "<<endl;
// for(int i=0;i<n;i++){
//     cout<<v[i]<< " ";
// }
// cout<<endl;
//   for(int i=0;i<n-1;i++){
//     diffmax+=abs(v[i]-v[i+1]);
// }
//     cout<<"diffmax "<<diffmax<<endl;
// return max(diff,max(diffmin,diffmax));