class Solution{
public:
    void Paranthesis(int i, int j, int n, int dp[30][30], char& name, string& result) {
        if (i == j) {
            result += name;
            name++;
            return;
        }
        result += '(';
        Paranthesis(i, dp[i][j], n, dp, name, result);
        Paranthesis(dp[i][j] + 1, j, n, dp, name, result);
        result += ')';
    }
    string matrixChainOrder(int p[], int n) {
        int dp[30][30] = { 0 };
        int m[30][30] = { 0 };
        int  q;
        for (int d = 2; d < n ; d++) {
            for (int i = 1; i < n - d + 1; i++) {
                int j = i + d - 1;
               m[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++) {
                    q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        dp[i][j] = k;
                    }
                }
            }
        }
        char name = 'A';
        string result;
        Paranthesis(1, n - 1, n, dp, name, result);
        return result;
    }
};