class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>result;
        int left = 0; 
        int right =c-1; 
        int top = 0;
        int bottom = r-1;
        int dir =1;
        while(left <= right && top <= bottom){
            if(dir ==1){
                for(int i=left;i<=right;i++){
                    result.push_back(matrix[top][i]);
                }
                dir =2;
                top++;
            }
            else if(dir ==2){
                for(int i=top;i<=bottom;i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
                dir =3;
                
            }
            else if(dir ==3){
                for(int i=right;i>=left;i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
                dir =4;
                
            }
            else if(dir ==4) {
                 for(int i=bottom;i>=top;i--){
                     result.push_back(matrix[i][left]);
                 }
                left++;
                dir =1;
            }
        }
        return result;
        
    }
};