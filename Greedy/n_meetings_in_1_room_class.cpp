#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n log n) - Due to sorting of the meetings by end times.
// Space Complexity: O(n) - To store the meeting details and meeting order in vectors.

class Meeting {
public:
    int start;
    int end;
    int index;

    // Constructor to initialize the Meeting class
    Meeting(int s, int e, int idx) : start(s), end(e), index(idx) {}
};

class Solution {
public:
    // Function to find the maximum number of meetings that can be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        vector<int> meeting_order;
        vector<Meeting> meetings;

        // Storing the meetings with start time, end time, and index.
        for (int i = 0; i < n; i++) {
            meetings.push_back(Meeting(start[i], end[i], i + 1));  // 1-based index
        }

        // Sorting based on the end time of the meetings.
        sort(meetings.begin(), meetings.end(), [](Meeting &a, Meeting &b) {
            return a.end < b.end;
        });

        // Initialize by selecting the first meeting.
        int cnt = 1;
        int freetime = meetings[0].end;
        meeting_order.push_back(meetings[0].index);

        // Checking for the next possible meetings.
        for (int i = 1; i < n; i++) {
            if (meetings[i].start > freetime) {  // If the meeting starts after the previous one ends.
                cnt++;
                freetime = meetings[i].end;
                meeting_order.push_back(meetings[i].index);
            }
        }

        // Printing the order of meetings (optional).
        cout << "Meeting order: ";
        for (int i : meeting_order) {
            cout << i << " ";
        }
        cout << endl;

        return cnt;
    }
};

int main() {
    Solution sol;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    
    int max_meetings = sol.maxMeetings(n, start, end);
    cout << "Maximum number of meetings that can be held: " << max_meetings << endl;

    return 0;
}
