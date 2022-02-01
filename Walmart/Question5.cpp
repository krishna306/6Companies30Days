/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sum(Node* root){
        if(root == NULL)return 0;
        return sum(root->left)+sum(root->right)+root->data;
    }
    void toSumTree(Node *node){
        if(node == NULL)return;
        int s = sum(node)-node->data;
        node->data = s;
        toSumTree(node->left);
        toSumTree(node->right);
    }
};