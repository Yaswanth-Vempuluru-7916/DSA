#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

class Solution
{
public:
    int findContentChildrenNormal(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m = g.size(), n = s.size(), i = 0, j = 0, cnt = 0;

        while (i < m && j < n)
        {
            if (s[j] >= g[i])
            {
                i++;
                j++;
                cnt++;
            }
            else
            {
                j++;
            }
        }

        return cnt;
    }
    int findContentChildren(vector<int> &greedFactors, vector<int> &cookieSizes)
    {
        sort(greedFactors.begin(), greedFactors.end());
        sort(cookieSizes.begin(), cookieSizes.end());

        int numberOfChildren = greedFactors.size();
        int numberOfCookies = cookieSizes.size();
        int childIndex = 0, cookieIndex = 0, contentChildrenCount = 0;

        while (childIndex < numberOfChildren && cookieIndex < numberOfCookies)
        {
            if (cookieSizes[cookieIndex] >= greedFactors[childIndex])
            {
                childIndex++;
                cookieIndex++;
                contentChildrenCount++;
            }
            else
            {
                cookieIndex++;
            }
        }

        return contentChildrenCount;
    }
};

int main()
{
    Solution solution;

    // Input arrays
    vector<int> greedFactors = {1, 2}; // Greed factor of children
    vector<int> cookieSizes = {1, 2,3};     // Sizes of cookies

    // Checking if arrays are non-empty
    if (greedFactors.empty())
    {
        cout << "Error: Greed factors array is empty!" << endl;
        return 1;
    }

    if (cookieSizes.empty())
    {
        cout << "Error: Cookie sizes array is empty!" << endl;
        return 1;
    }

    // Find and print the maximum number of content children
    int result = solution.findContentChildren(greedFactors, cookieSizes);

    cout << "Maximum number of content children: " << result << endl;

    return 0;
}
