 
#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode* curr = root;
        while(curr!=nullptr){

            if(!curr->left){
                inorder.push_back(curr->val);
                curr = curr->right;
            }else{

            TreeNode* prev = curr->left;

            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }

            if(!prev->right){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }

            }


        }

        return inorder;
    }

    int main(){
        TreeNode* root = nullptr;
        vector<int>inorder = inorderTraversal(root);
    }