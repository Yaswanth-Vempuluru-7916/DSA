#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) // Fixed the constructor parameter name to 'data'
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inorder(Node *root,vector<int>&in)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}



void levelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << frontNode->data << " "; // Print data with a space
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
    }
}

Node *insertBST(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data); // Directly return the new node
    }

    if (data < root->data)
    {
        root->left = insertBST(root->left, data); // Correctly set the left child
    }
    else
    {
        root->right = insertBST(root->right, data); // Correctly set the right child
    }

    return root; // Return the unchanged root pointer
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
}


Node* balancedBST(int s, int e ,vector<int>in){
    
    if(s>e){
        return nullptr;
    }

    int mid = s + (e-s)/2;

    Node* root = new Node(in[mid]);
    root->left = balancedBST(s,mid-1,in);
    root->left = balancedBST(mid+1,e,in);
    return root;

}

int main()
{
    Node *root = nullptr;
    // 10 8 21 7 27 5 4 3 -1
    //50 20 70 10 30 90 110 —1
    cout << "Enter data to create BST (end with -1): ";
    takeInput(root);
    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);
    vector<int>in;
    inorder(root,in);

   Node* balancedRoot =  balancedBST(0,in.size()-1,in);

    return 0;
}
