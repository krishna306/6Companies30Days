//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
//Function to count number of subtrees having sum equal to given sum.
int result=0;
int find(Node * root,int X){
    if(root == NULL){
        return 0;
    }
    int l = find(root->left,X);
    int r = find(root->right,X);
    int sum =  root->data + l+r;
    if(sum ==X){
        result++;
    }
    return sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
	result=0;
	int x = find(root,X);
	return result;
}
