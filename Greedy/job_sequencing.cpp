#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is done before or on the deadline
};

// Time Complexity: O(n log n + n * max_deadline)
// Space Complexity: O(max_deadline)

class Solution
{
public:
    static bool cmp(Job arr1, Job arr2)
    {
        return arr1.profit > arr2.profit;
    }

    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // Sorting jobs based on profit in descending order.

        //    sort(arr, arr + n, cmp);

        sort(arr, arr + n, [](Job a, Job b){
             return a.profit > b.profit;
              });

        int cnt = 0, totalProfit = 0, maxdead = -1;

        // Finding the maximum deadline.
        for (int i = 0; i < n; i++)
        {
            maxdead = max(maxdead, arr[i].dead);
        }

        // Array to keep track of free time slots.
        vector<int> hash(maxdead + 1, -1);

        // Assign jobs to free slots.
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                // If the slot is free, assign the job.
                if (hash[j] == -1)
                {
                    hash[j] = arr[i].id;
                    totalProfit += arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }

        return {cnt, totalProfit};
    }
};

int main()
{
    Job arr[] = {{1, 2, 100}, {2, 1, 50}, {3, 2, 10}, {4, 1, 20}, {5, 3, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution sol;
    vector<int> result = sol.JobScheduling(arr, n);

    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Total profit: " << result[1] << endl;

    return 0;
}
