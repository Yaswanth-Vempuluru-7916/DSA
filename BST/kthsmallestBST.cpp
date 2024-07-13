#include<bits/stdc++.h>
using namespace std;

class Node{
    public : 
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node* insertBST(Node* root,int data){
    if(root==nullptr){
        root = new Node(data);
        return root;
    }

    if(root->data>data){
        root->right = insertBST(root->right,data);
    }else{
        root->left = insertBST(root->left,data);
    }

    return root;
}

void takeInput(Node*& root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insertBST(root,data);
        cin>>data;
    }
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

int kthSmallest(Node *root,int& i,int k){

    if(root==nullptr){
        return -1;
    }

    //Left

    int left = kthSmallest(root->left,i,k);

    if(left!=-1){
        return left;
    }

    //Node
    i++;

    if(i==k){
        return root->data;
    }

    //Right
    return kthSmallest(root->right,i,k);
}
int main(){
    Node* root = nullptr;
    cout<<"Enter the data and end with -1"<<endl;
    takeInput(root);
    cout<<"Levl order Traversal "<<endl;
    levelOrderTraversal(root);
    int i=0,k;
    cout<<"kth smallest "<<kthSmallest(root,i,k)<<endl;
}