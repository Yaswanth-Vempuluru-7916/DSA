#include<bits/stdc++.h>
using namespace std;


    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

void mergeTwoSortedArrays( vector<int>bst1, vector<int>bst2, vector<int>&ans){
    int i=0,j=0,k=0;

    while(i<bst1.size() && j<bst2.size()){
        if(bst1[i]<bst2[j]){
            ans[k++]=bst1[i++];
        }else{
            ans[k++]=bst2[j++];
        }
    }

    while(i<bst1.size()){
        ans[k++]=bst1[i++];
    }
    while(j<bst2.size()){
        ans[k++]=bst2[j++];
    }
}
void inorderTraverse(TreeNode *root , vector<int>&inorder){

    if(root==nullptr){
        return;
    }

    inorderTraverse(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraverse(root->right, inorder);
}

TreeNode* inorderToBalancedBST(int s,int e,vector<int>&ans){

    if(s>e){
        return nullptr;
    }

    int mid = s+(e-s)/2;

    TreeNode* root = new TreeNode(ans[mid]);
    root->left = inorderToBalancedBST(s, mid-1, ans);
    root->right = inorderToBalancedBST(mid+1, e, ans);

    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int>bst1,bst2;
    inorderTraverse(root1, bst1);
    inorderTraverse(root2, bst2);
    vector<int>ans(bst1.size()+bst2.size());
    mergeTwoSortedArrays(bst1,bst2,ans);
    return ans;
    // int s=0,e=ans.size()-1;
    // return inorderToBalancedBST(s,e,ans);
}


int main() {
    // Creating two BSTs
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(5);

    // Merging the BSTs
    vector<int> mergedList = mergeBST(root1, root2);

    // Printing the merged list
    cout << "Merged BSTs into sorted list: ";
    for (int val : mergedList) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup dynamically allocated memory
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}