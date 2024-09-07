#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    vector<map<int, string>> vec = {
        {{3, "apple"}, {1, "banana"}},
        {{2, "cherry"}, {4, "date"}},
        {{1, "apple"}, {5, "elderberry"}}};

    // for(auto mp:vec){
    //     for(auto it = mp.begin() ; it!=mp.end();it++){
    //         cout<<"Key : "<<it->first<< " "<<"Value : "<<it->second<<endl;
    //     }
    //     cout<<endl;
    // }

    // Key : 1 Value : banana
    // Key : 3 Value : apple

    // Key : 2 Value : cherry
    // Key : 4 Value : date

    // Key : 1 Value : apple
    // Key : 5 Value : elderberry

    for (auto mp : vec)
    {
        for (auto pair : mp)
        {
            cout << "Key : " << pair.first << " " << "Value : " << pair.second << endl;
        }
        cout << endl;
    }

    sort(vec.begin(), vec.end(), [](const map<int, string> &a, const map<int, string> &b)
         { return a.begin()->first < b.begin()->first; });

    cout << "After sorting : " << endl;

    for (auto mp : vec)
    {
        for (auto pair : mp)
        {
            cout << "Key : " << pair.first << " " << "Value : " << pair.second << endl;
        }
        cout << endl;
    }


    //     After sorting :
    // Key : 1 Value : banana
    // Key : 3 Value : apple

    // Key : 1 Value : apple
    // Key : 5 Value : elderberry

    // Key : 2 Value : cherry
    // Key : 4 Value : date
}