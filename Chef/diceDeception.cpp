#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            v.push_back(ele);
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            if ((v[i] <= (7 - v[i])) && (k > 0))
            {
                v[i] = 7 - v[i];
                k--;
            }
        }

        int sum = 0;
        for (auto nums : v)
        {
            sum += nums;
        }

        cout << sum << endl;
    }
}
