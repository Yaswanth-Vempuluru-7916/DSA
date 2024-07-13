#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node *buildTree(node *root)
{
    cout << "enter the data : " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "Enter the data to enter to the left of" << data << ":\n";
    root->left = buildTree(root->left);
    cout << "Enter the data to enter to the right of" << data << ":\n";
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    // level ayyaka oka seperator veyy
    q.push(nullptr);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        
        if(temp==nullptr){
            //mundu level aipoyindhi
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
        cout << temp->data << " ";

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }

        }

    }
}

void inorder(node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(node*& root){
    queue<node*>q;
    cout<<"Enter the root data : "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();
        
        cout<<"Enter the left node data for : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter the right node data for : "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{

    node *root = nullptr;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    // root = buildTree(root);
    // // 1 3 7 -1 -1 11 -1 -1  5 17 -1 -1 -1
    // // level order traversal
    // cout << "\nPrintng the level order traversal\n";
    // levelOrderTraversal(root);

    // cout<<"\nInorder Traversal is"<<endl;
    // inorder(root);

    // cout<<"\nPreorder Traversal is"<<endl;
    // preorder(root);

    // cout<<"\nPostOrder Traversal is"<<endl;
    // postorder(root);

    return 0;
}