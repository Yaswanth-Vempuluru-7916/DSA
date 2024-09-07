#include <bits/stdc++.h>
using namespace std;

int main()
{

    map<int, string> mp = {{1, "Apple"}, {5, "Mango"}, {6, "Pear"}, {2, "Pomegranate"}};

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    // 1 Apple
    // 2 Pomegranate
    // 5 Mango
    // 6 Pear

    for (auto pair : mp)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    // 1 Apple
    // 2 Pomegranate
    // 5 Mango
    // 6 Pear
    vector<pair<int, string>> vec(mp.begin(), mp.end());

    sort(vec.begin(), vec.end(), [](const pair<int, string> &a, const pair<int, string> &b)
         { 
            return a.second < b.second;
         });

    cout << endl;

    for (auto pair : vec)
    {
        cout << pair.second << " " << pair.first << endl;
    }


    // Apple 1
    // Mango 5
    // Pear 6
    // Pomegranate 2


    return 0;
}