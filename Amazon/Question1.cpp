class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        vector<vector<int>>a(K+1,vector<int>(N));
        for(int t = 1; t <= K;t++){
            int Max = INT_MIN;
            for(int d=1; d < N; d++){
                if(a[t - 1][d - 1] - A[d - 1] > Max){
                    Max = a[t - 1][d - 1] - A[d - 1];
                }
                if(Max + A[d] > a[t][d-1]){
                    a[t][d] = Max + A[d];
                }
                else{
                    a[t][d] = a[t][d-1];
                }
            }
        }
        return a[K][N-1];
    }
};