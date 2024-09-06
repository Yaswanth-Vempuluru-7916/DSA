#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter the root data: ";
    int data;
    cin >> data;
    if (data == -1)
    {
        root = nullptr;
        return;
    }
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        cout << "Enter the left node data for " << front->data << ": ";
        int leftData;
        cin >> leftData;
        cout << endl;

        if (leftData != -1)
        {
            front->left = new Node(leftData);
            q.push(front->left);
        }

        cout << "Enter the right node data for " << front->data << ": ";
        int rightData;
        cin >> rightData;
        cout << endl;

        if (rightData != -1)
        {
            front->right = new Node(rightData);
            q.push(front->right);
        }
    }
}

Node *findNode(Node *root, int data)
{
    if (root == nullptr || root->data == data)
    {
        return root;
    }
    Node *left = findNode(root->left, data);
    if (left != nullptr)
    {
        return left;
    }
    return findNode(root->right, data);
}

Node *LCA(Node *root, Node *p, Node *q)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data < p->data && root->data < q->data)
    {
        return LCA(root->right, p, q);
    }
    else if (root->data > p->data && root->data > q->data)
    {
        return LCA(root->left, p, q);
    }
    else
    {
        return root;
    }
}

Node *LCAIterative(Node *root, Node *p, Node *q)
{

    while (root != nullptr)
    {

        if (root->data < p->data && root->data < q->data)
        {
            root = root->right;
        }
        else if (root->data > p->data && root->data > q->data)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }
}

int main()
{

    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
    // 25 12 30 6 -1 28 35 1 9 -1 27 32 -1 -1 -1 7 -1 -1 -1 -1 -1 -1 -1
    Node *root = nullptr;
    buildFromLevelOrder(root);

    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return 0;
    }

    int pData, qData;
    cout << "Enter data for first node: ";
    cin >> pData;
    cout << "Enter data for second node: ";
    cin >> qData;

    Node *p = findNode(root, pData);
    Node *q = findNode(root, qData);

    if (p == nullptr || q == nullptr)
    {
        cout << "One or both of the nodes are not present in the tree." << endl;
    }
    else
    {
        Node *lca = LCA(root, p, q);
        if (lca != nullptr)
        {
            cout << "LCA of " << pData << " and " << qData << " is: " << lca->data << endl;
        }
        else
        {
            cout << "LCA does not exist." << endl;
        }
    }

    return 0;
}