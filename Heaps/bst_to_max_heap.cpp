#include <iostream>
#include <vector>
using namespace std;

// Definition of the tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function for in-order traversal to store the elements in sorted order
    void inorder_traversal(Node* root, vector<int>& inorder) {
        if (!root) return;  // Base case
        inorder_traversal(root->left, inorder);  // Traverse the left subtree
        inorder.push_back(root->data);  // Visit the node
        inorder_traversal(root->right, inorder);  // Traverse the right subtree
    }

    // Function for post-order traversal to convert the tree into a max-heap
    void postorder(Node* root, vector<int>& inorder, int& index) {
        if (!root) return;  // Base case
        postorder(root->left, inorder, index);  // Traverse the left subtree
        postorder(root->right, inorder, index);  // Traverse the right subtree
        root->data = inorder[index++];  // Replace node's value with the sorted array element
    }

    // Main function to convert the given BST to max-heap
    void convertToMaxHeapUtil(Node* root) {
        vector<int> inorder;  // Vector to store the inorder traversal elements
        inorder_traversal(root, inorder);  // Get elements in sorted order (in-order traversal)
        int index = 0;  // Index to traverse the inorder array during post-order conversion
        postorder(root, inorder, index);  // Convert the tree using post-order traversal
    }
};

// Utility function to create a new tree node
Node* createNode(int val) {
    return new Node(val);
}

// Utility function to print the tree in post-order to verify max-heap conversion
void postorderPrint(Node* root) {
    if (!root) return;
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";
}

int main() {
    // Constructing a sample Binary Search Tree (BST)
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    Solution solution;
    solution.convertToMaxHeapUtil(root);  // Convert BST to max-heap

    // Printing post-order traversal of the converted max-heap
    cout << "Post-order traversal of the converted max-heap: ";
    postorderPrint(root);  // Expected output should represent max-heap
    cout << endl;

    return 0;
}

/*
Time Complexity:
- The in-order traversal of the BST takes O(n), where n is the number of nodes.
- The post-order traversal to convert the tree into a max-heap also takes O(n).
Therefore, the overall time complexity is O(n).

Space Complexity:
- The additional space used is for storing the in-order traversal elements, which is O(n).
- The recursive call stack for in-order and post-order traversals also takes O(h) space, where h is the height of the tree. In the worst case, the height can be O(n) for a skewed tree.
Therefore, the overall space complexity is O(n).
*/
