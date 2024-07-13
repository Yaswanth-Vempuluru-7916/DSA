
    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };



bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root==nullptr){
        return false;
    }

    if(root->data == x){
        return true;
    }
    
    if(root->data<x){
      return searchInBST(root->right, x);
    }else{
       return searchInBST(root->left, x);

    }
}
bool searchIterativeInBST(BinaryTreeNode<int> *root, int x) {
    if(root==nullptr){
        return false;
    }

   BinaryTreeNode<int> *temp=root;

   while(temp!=nullptr){
    if(temp->data==x){
        return true;
    }

    if(temp->data>x){
        temp = temp->left;
    }else{
        temp = temp->right;

    }
   }
}