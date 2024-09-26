#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(n) because of the additional storage for non-overlapping intervals
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals, vector<vector<int>> &nonOverlappingIntervals)
    {
        // Check if intervals are empty
        if (intervals.empty())
            return 0;

        int nonOverlapCount = 0, lastFreeEnd = 0; // Initialize counters
        // To store non-overlapping intervals

        // Sort intervals based on the end time to maximize the non-overlapping intervals
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        // The first interval is always part of the non-overlapping set
        nonOverlapCount = 1;
        lastFreeEnd = intervals.begin()->at(1); // Track the end time of the first interval
        nonOverlappingIntervals.push_back(*intervals.begin());

        // Iterate over the remaining intervals to check for non-overlap
        for (auto it = intervals.begin() + 1; it != intervals.end(); it++)
        {
            if (it->at(0) >= lastFreeEnd)
            {
                nonOverlapCount++;
                lastFreeEnd = it->at(1); // Update the free end time to the current interval's end
                nonOverlappingIntervals.push_back(*it);
            }
        }

        // The number of intervals to erase is the total intervals minus the non-overlapping intervals
        return intervals.size() - nonOverlappingIntervals.size();
    }
};

// Main function to test the solution
int main()
{
    Solution sol;

    // Example test case
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}, {2, 5}};

    vector<vector<int>> nonOverlappingIntervals;
    // Call the function to erase overlapping intervals
    int result = sol.eraseOverlapIntervals(intervals, nonOverlappingIntervals);

    // Output the result
    cout << "Number of intervals to erase: " << result << endl;

    //Non Overlapping Intervals are
    cout << "Non Overlapping Intervals are " <<  endl;
      for (const auto& interval : nonOverlappingIntervals) {
            cout << "[" << interval[0] << ", " << interval[1] << "] ";
        }
        cout << endl;
    return 0;
}
