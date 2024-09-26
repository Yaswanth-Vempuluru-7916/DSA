#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n log n) - Due to sorting of meetings based on end times.
// Space Complexity: O(n) - To store the meeting details in the vector.

class Solution {
public:
    // Function to find the maximum number of meetings that can be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[],vector<int>& meeting_order) {
        
        int cnt = 0, freetime = 0;
        vector<pair<int, pair<int, int>>> v;
        
        // Storing the meetings with start time, end time, and index.
        for(int i = 0; i < n; i++) {
            v.push_back({start[i], {end[i], i + 1}});
        }
        
        // Sorting based on the end time of the meetings.
        sort(v.begin(), v.end(), [](pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
            return a.second.first < b.second.first;
        });
        
        // Initialize by selecting the first meeting.
        cnt = 1;
        freetime = v[0].second.first;
        meeting_order.push_back(v[0].second.second);
        
        // Checking for the next possible meetings.
        for(int i = 1; i < n; i++) {
            if(v[i].first > freetime) {  // If the meeting starts after the previous one ends.
                cnt++;
                freetime = v[i].second.first;
                meeting_order.push_back(v[i].second.second);
            }
        }
        
        // Return the number of meetings that can be attended.
        return cnt;
    }
};

int main() {
    Solution sol;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    vector<int> meeting_order;
    int max_meetings = sol.maxMeetings(n, start, end,meeting_order);
    cout << "Maximum number of meetings that can be held: " << max_meetings << endl;
    cout<<"The meeting order is : ";
    for(auto elem : meeting_order){
        cout<<elem<<" ";
    }

    return 0;
}
