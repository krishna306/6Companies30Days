class Solution {
public:
    int maxTime = 0;
    void burnTree(Node* root, Node* blockNode, int time) {
        if (root == NULL || root == blockNode) {
            return;
        }
        maxTime = max(maxTime, time);
        burnTree(root->left, blockNode, time + 1);
        burnTree(root->right, blockNode, time + 1);
    }
    int burningTree(Node* root, int val) {
        if (root == NULL) {
            return -1;
        }
        if (root->data == val) {
            burnTree(root, NULL, 0);
            return 1;
        }
        int leftTime = burningTree(root->left, val);
        if (leftTime != -1) {
            burnTree(root, root->left, leftTime);
            return leftTime + 1;
        }
        int rightTime = burningTree(root->right, val);
        if (rightTime != -1) {
            burnTree(root, root->right, rightTime);
            return rightTime + 1;
        }
        return -1;
    }
    int minTime(Node* root, int target){
        burningTree(root, target);
        return maxTime;
    }
};