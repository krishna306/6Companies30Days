/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
        Node* construct(vector<vector<int>>& grid) {
        grid_ = move(grid);
        leaf_[0] = new Node(0, true);
        leaf_[1] = new Node(1, true);
        return dfs(0, 0, grid_.size());
        
        
    }
    vector<vector<int>> grid_;
    array<Node* , 2> leaf_;
    
    Node* dfs(int x, int y, int l){
        if (l == 1) return leaf_[grid_[x][y]];
        l /= 2;
        auto tl = dfs(x, y, l);
        auto tr = dfs(x, y+l, l);
        auto bl = dfs(x+l, y, l);
        auto br = dfs(x+l, y+l, l);
        if (tl == tr && tr == bl && bl == br) return tl;
        return new Node(0, false, tl, tr, bl, br);
        
    }
};