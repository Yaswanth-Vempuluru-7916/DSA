#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char comp(int a, int b)
{
    if (a < b)
    {
        return '<';
    }
    else if (a > b)
    {
        return '>';
    }
    else
    {
        return '=';
    }
}

int longestDangerousRange(vector<int> &height, int n)
{
    if (height.size() == 1 || height.size() == 2)
    {
        return height.size();
    }
    char prev = comp(height[0], height[1]);
    char curr;
    int cnt = 1, maxi = INT_MIN;
    // for(int i=1;i<n;i++){
    for (int j = 2; j < n; j++)
    {
        curr = comp(height[j - 1], height[j]);
        if (prev=='>' && curr=='<' || prev=='<'&&curr=='>')
        {
            cnt++;
        }
        else
        {
            maxi = max(cnt, maxi);
            cnt = 1;
        }
        prev = curr;
    }
    // }
            maxi = max(cnt, maxi);
    return maxi;
}

int main()
{

    // vector<int> height = {2, 8};
    vector<int> height = {1,2, 1,4};
    // vector<int>height={9, 4 ,2 ,10 ,7, 8, 8, 1, 9};
    cout<<"Max range is : "<<longestDangerousRange(height, height.size());

    return 0;
}