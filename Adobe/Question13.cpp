class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        vector<int>result;
        
        unordered_set<int> s;
        for(int i = 0; i < M ;i++){
            s.insert(B[i]);
        }
        
        
        for(int i = 0; i < N ;i++){
            if(s.find(A[i])!=s.end()){
                auto it = lower_bound(result.begin(),result.end(),A[i]);
                if(it==result.end()){
                    result.push_back(A[i]);
                }else{
                    *it = A[i];
                }
            }
        }
        
        return N+M-2*result.size();
    }
};