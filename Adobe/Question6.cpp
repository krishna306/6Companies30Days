// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution{
    public:
    vector<string> AllParenthesis(int n){
        vector<string>result;
        generateParenthesis("(",result,1,0,n);
        return result;
    }
    void generateParenthesis(string current,vector<string>&result,int lp,int rp,int n){
        if(current.length() == 2*n){
            result.push_back(current);
            return;
        }
        if(lp<n){
            generateParenthesis(current+"(",result,lp+1,rp,n);
        }
        if(rp <n && rp < lp){
            generateParenthesis(current+")",result,lp,rp+1,n);
        }
    }
};