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

Node *createParentMapping(map<Node *, Node *> &nodeToParent, Node *&root, int target)
{
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = nullptr;
    Node *targetNode = nullptr;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            targetNode = front;
        }

        if (front->left)
        {
            q.push(front->left);
            nodeToParent[front->left] = front;
        }

        if (front->right)
        {
            q.push(front->right);
            nodeToParent[front->right] = front;
        }
    }

    return targetNode;
}

int burnTree(Node *targetNode, map<Node *, Node *> nodeToParent)
{
    int time = 0;

    map<Node *, bool> visited;

    queue<Node *> q;

    q.push(targetNode);
    visited[targetNode] = true;

    while (!q.empty())
    {
        int size = q.size();
        bool flag = false;

        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }

            if (front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }

            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }

        if (flag)
        {
            time++;
        }
    }

    return time;
}

int main()
{
    Node *root = nullptr;
    buildFromLevelOrder(root);
//1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return 0;
    }

    int target;
    //5
    cout << "Enter the target Node: ";
    cin >> target;
    cout << endl;
    // Create node-to-parent mapping
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(nodeToParent, root, target);

    if (targetNode == nullptr)
    {
        cout << "Target node not found in the tree." << endl;
        return 0;
    }

    // Burning the tree
    int time = burnTree(targetNode, nodeToParent);
    cout << "\nThe time taken to burn the tree is: " << time << " units." << endl;

    return 0;
}
