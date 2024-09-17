#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    // Custom comparator for min-heap (priority queue)
    class cmp {
    public:
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // Min-heap: smallest element at the top
        }
    };

    // Function to merge K sorted linked lists
    // Time Complexity: O(N log K), where N is the total number of elements and K is the number of lists.
    // Space Complexity: O(K), as the priority queue stores K elements at a time.
    Node* mergeKLists(vector<Node*>& arr) {
        // Min-heap to hold the smallest elements from each list
        priority_queue<Node*, vector<Node*>, cmp> p(arr.begin(), arr.end());

        // Dummy node to start the merged list
        Node* root = new Node(0);
        Node* tail = root;
        Node* temp;

        // While the heap is not empty
        while (!p.empty()) {
            temp = p.top();
            p.pop();  // Remove the smallest element
            tail->next = temp;  // Attach it to the merged list
            tail = tail->next;

            if (temp->next) {
                p.push(temp->next);  // Push the next element from the same list
            }
        }
        return root->next;  // Return the merged list (skipping the dummy node)
    }
};

// Utility function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function to test the solution
int main() {
    // Create some linked lists
    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node* list3 = new Node(2);
    list3->next = new Node(6);

    // Store the heads of the linked lists in a vector
    vector<Node*> lists = {list1, list2, list3};

    // Create a Solution object
    Solution sol;

    // Merge the K sorted linked lists
    Node* mergedList = sol.mergeKLists(lists);

    // Print the merged list
    cout << "Merged list: ";
    printList(mergedList);

    return 0;
}
