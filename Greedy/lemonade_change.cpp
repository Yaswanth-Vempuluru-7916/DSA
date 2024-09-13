#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(n)
// Explanation: The loop runs once for each customer (or bill), 
// so the algorithm processes each element in the 'bills' array exactly once.
// Hence, the time complexity is linear with respect to the number of bills, which is O(n).

// Space Complexity: O(1)
// Explanation: The algorithm uses only a few integer variables (`five`, `ten`, and `twenty`) 
// to keep track of the number of $5, $10, and $20 bills. 
// This requires constant space, regardless of the input size. Therefore, the space complexity is O(1).

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0; // Track the number of $5, $10, and $20 bills

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) { // Customer gives a $5 bill
                five++; // Increase the count of $5 bills
            } else if (bills[i] == 10) { // Customer gives a $10 bill
                if (five > 0) { // Check if we have a $5 bill to give as change
                    five--; // Use one $5 bill
                    ten++;  // Increase the count of $10 bills
                } else {
                    return false; // Cannot provide change
                }
            } else { // Customer gives a $20 bill
                if (five > 0 && ten > 0) { // Prefer to use one $10 and one $5 bill as change
                    ten--; // Use one $10 bill
                    five--; // Use one $5 bill
                    twenty++; // Increase the count of $20 bills
                } else if (five >= 3) { // Otherwise, use three $5 bills as change
                    five -= 3;
                    twenty++; // Increase the count of $20 bills
                } else {
                    return false; // Cannot provide change
                }
            }
        }

        return true; // Successfully provided change for all customers
    }
};

int main() {
    Solution solution;

    // Example: Bills given by customers
    vector<int> bills = {5, 5, 5, 10, 20}; 
    
    // Call the lemonadeChange function
    if (solution.lemonadeChange(bills)) {
        cout << "Change can be provided for all customers." << endl;
    } else {
        cout << "Change cannot be provided for some customers." << endl;
    }

    return 0;
}
