#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> attA, defA, attP, defP;
        int aA = 0, dA = 0, aP = 0, dP = 0;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            attA.push_back(ele);
        }
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;

            defA.push_back(ele);
        }
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;

            attP.push_back(ele);
        }
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;

            defP.push_back(ele);
        }

        for(int i = 0;i<n;i++){
            aA+=attA[i];
            dA+=defA[i];
            aP+=attP[i];
            dP+=defP[i];
        }

        if (aA > aP && dA > dP)
        {
            cout << "A" << endl;
        }
        else if (aA < aP && dA < dP)
        {
            cout << "P" << endl;
        }
        else
        {
            cout << "DRAW" << endl;
        }
    }
}
