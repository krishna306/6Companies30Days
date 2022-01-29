class Solution{
    public:
    void dfs(int src,vector<vector<int>>&g,vector<int>&vis,string &ans){
        vis[src]=1;
        for(auto x : g[src]){
            if(!vis[x]){
                dfs(x,g,vis,ans);
            }
        }
        char ch = src + 'a';
        ans= ch + ans;
    }
    string findOrder(string dict[], int N, int K) {
       vector<vector<int>>g(K);
       for(int i=0;i<N-1;i++){
           string s1 = dict[i];
           string s2 = dict[i+1];
           for(int j=0;j<min(s1.length(),s2.length());j++){
               if(s1[j] != s2[j]){
                   g[s1[j]-'a'].push_back(s2[j]-'a');
                   break;
               }
           }
       }
       vector<int>vis(K,0);
       string ans ="";
       for(int i=0;i<K;i++){
           if(!vis[i]){
               dfs(i,g,vis,ans);
           }
       }
       return ans ;
    }
};