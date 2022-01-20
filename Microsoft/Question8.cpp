class Solution
{
public:
    //Function to connect nodes at same level.
    void connect(Node* root)
    {
        queue<pair<Node*,int>>q;
        int level = 0;

        q.push(make_pair(root,level));
        Node* prev = NULL;
        while (!q.empty()) {
            pair<Node * ,int >temp  = q.front();

            if (temp.second != level) {
                prev->nextRight = NULL;
                level = temp.second;
            }
            else {
                if (prev != NULL) {
                    prev->nextRight = temp.first;
                }
            }
            prev = temp.first;;
            if (temp.first->left != NULL) {
                q.push(make_pair(temp.first->left,temp.second+1));
            }
            if (temp.first->right != NULL) {
                q.push(make_pair(temp.first->right, temp.second + 1));
            }
            q.pop();
        }
    }
};
