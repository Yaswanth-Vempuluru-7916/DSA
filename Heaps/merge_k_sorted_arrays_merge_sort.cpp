#include <iostream>
#include <vector>
using namespace std;
/*
Time Complexity (TC):
    • The time complexity is O(n log n), where n k x k is the total number of
        elements in the array.
    • Merge sort has a time complexity of log n) for sorting an array of
        size n.
Space Complexity (SC):
    • The space complexity is O(n), where n is the total number of elements. This
    includes the space used by the recursive stack during merge sort and the
    temporary storage used for merging subarrays.
*/
class Solution
{
public:
    // Function to merge two sorted subarrays of 'ans'.
    // Time Complexity: O(end - start + 1), linear merging of two subarrays.
    // Space Complexity: O(end - start + 1), for temporary storage.
    void merge(vector<int> &ans, int start, int mid, int end)
    {
        int i = start, j = mid + 1;
        vector<int> temp;

        // Merge the two subarrays
        while (i <= mid && j <= end)
        {
            if (ans[i] < ans[j])
            {
                temp.push_back(ans[i++]);
            }
            else
            {
                temp.push_back(ans[j++]);
            }
        }

        // Add remaining elements from the left subarray
        while (i <= mid)
            temp.push_back(ans[i++]);

        // Add remaining elements from the right subarray
        while (j <= end)
            temp.push_back(ans[j++]);

        // Copy the merged elements back to 'ans'
        for (int i = start; i <= end; i++)
        {
            ans[i] = temp[i - start];
        }
    }

    // Function to perform merge sort on 'ans' with K portions of size 'portions'.
    // Time Complexity: O(n log n), where n is the total number of elements in 'ans'.
    // Space Complexity: O(n), for recursive stack and temporary storage.
    void mergesort(vector<int> &ans, int start, int end, int portions, int k)
    {
        if (portions < 2)
            return;

        int mid = start + (portions / 2) * k - 1;

        // Recursively split and sort the subarrays
        mergesort(ans, start, mid, portions / 2, k);
        mergesort(ans, mid + 1, end, portions - portions / 2, k);

        // Merge the sorted subarrays
        merge(ans, start, mid, end);
    }

    // Function to merge k sorted arrays.
    // Time Complexity: O(n log n), where n = K * K (total number of elements).
    // Space Complexity: O(n), for storing the merged array and recursion stack.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> ans;

        // Flatten the 2D array into a 1D array
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                ans.push_back(arr[i][j]);
            }
        }

        int portions = k;
        // Perform merge sort on the flattened array
        mergesort(ans, 0, ans.size() - 1, portions, k);

        return ans;
    }
};

// Function to print the array
void printArray(const vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Main function to test the solution
int main()
{
     int k = 5;
    vector<vector<int>> arr = {
        {1, 5, 9, 13, 17},
        {2, 6, 10, 14, 18},
        {3, 7, 11, 15, 19},
        {4, 8, 12, 16, 20},
        {21, 22, 23, 24, 25}
    };

    Solution sol;
    vector<int> mergedArray = sol.mergeKArrays(arr, k);

    cout << "Merged Array: ";
    printArray(mergedArray);

    return 0;
}
