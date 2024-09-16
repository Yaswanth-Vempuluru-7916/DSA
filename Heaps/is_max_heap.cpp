#include <iostream>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Function to check if the tree is a Complete Binary Tree (CBT)
    bool CBT(struct Node* root, int total, int index) {
        if (!root) return true;  // Null node is always CBT
        
        // If the index is out of range, it is not a CBT
        if (index >= total) return false;
        
        // Check the left and right subtrees recursively
        bool left = CBT(root->left, total, 2 * index + 1);
        bool right = CBT(root->right, total, 2 * index + 2);
        
        return left && right;
    }

    // Function to count the number of nodes in the tree
    int count_nodes(struct Node* root) {
        if (!root) return 0;
        int left = count_nodes(root->left);
        int right = count_nodes(root->right);
        return 1 + left + right;
    }

    // Function to check if the tree satisfies the max-heap property
    bool Max_Heap(struct Node* root) {
        // Leaf node or one child node is automatically valid
        if (!root->left && !root->right) return true;
        
        // If the left child exists, check its value with the parent
        if (root->left) {
            if (root->data < root->left->data) return false;
            if (!Max_Heap(root->left)) return false;
        }
        
        // If the right child exists, check its value with the parent
        if (root->right) {
            if (root->data < root->right->data) return false;
            return Max_Heap(root->right);
        }
        
        return true;  // If both checks pass, it's a max-heap
    }

    // Main function to check if the binary tree is a heap
    bool isHeap(struct Node* tree) {
        int count = count_nodes(tree);  // Count the total number of nodes
        int index = 0;
        
        // Check if the tree is a Complete Binary Tree
        if (!CBT(tree, count, index)) return false;
        
        // Check if the tree satisfies the max-heap property
        return Max_Heap(tree);
    }
};

// Helper function to create a new node
Node* createNode(int val) {
    return new Node(val);
}

// Main function to test the solution
int main() {
    Solution solution;

    // Create a test binary tree
    Node* root = createNode(10);
    root->left = createNode(9);
    root->right = createNode(8);
    root->left->left = createNode(7);
    root->left->right = createNode(6);
    root->right->left = createNode(5);
    root->right->right = createNode(4);

    // Check if the binary tree is a heap
    if (solution.isHeap(root)) {
        cout << "The binary tree is a heap." << endl;
    } else {
        cout << "The binary tree is not a heap." << endl;
    }

    return 0;
}

/*
Time Complexity:
1. `CBT` (Complete Binary Tree check): O(n), where n is the number of nodes. This is because we visit each node once.
2. `count_nodes` (Count total nodes): O(n), as it recursively counts the nodes.
3. `Max_Heap` (Max-Heap property check): O(n), as it traverses the tree once.

Overall Time Complexity: O(n), where n is the total number of nodes in the tree.

Space Complexity:
1. The space complexity is O(h), where h is the height of the tree, due to the recursive stack used for both the CBT and Max-Heap checks.
2. In the worst case, the space complexity is O(n) for a skewed tree.

Overall Space Complexity: O(n) in the worst case, where n is the total number of nodes.
*/
