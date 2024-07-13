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

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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

Node *minVal(Node *root)
{
    Node *temp = root;

    while (temp->left != nullptr)
    {
        temp = temp->left;
    }

    return temp;
}
Node *maxVal(Node *root)
{
    Node *temp = root;

    while (temp->right != nullptr)
    {
        temp = temp->right;
    }

    return temp;
}

Node *deleteFromBST(Node *root, int val)
{

    if (root == nullptr)
    {
        return root;
    }

    if (root->data == val)
    {
        // 0 child

        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // 1st child
        if (root->left != nullptr && root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == nullptr && root->right != nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child

        if (root->left != nullptr && root->right != nullptr)
        {
            // left se max
            // or
            // right me se min

            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
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
    cout << "\nPreorder:";
    preorder(root);
    cout << "\nInorder:";
    inorder(root);
    cout << "\nPostorder:";
    postorder(root);
    cout << "\nMinValue: " << minVal(root)->data;
    cout << "\nMaxValue: " << maxVal(root)->data;
    deleteFromBST(root,50);
    cout << "\nLevel Order Traversal After deleting :" << endl;
    levelOrderTraversal(root);

    return 0;
}
