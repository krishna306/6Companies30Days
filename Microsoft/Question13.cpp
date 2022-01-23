class Solution
{
    int vis[100001];
    int dfs(int i, vector<int> adj[], int c, int d){
        vis[i] =1;
        for(auto x : adj[i]){
            if(i == c && x == d){
                continue;
            }
            if(!vis[x]) {
                dfs(x, adj, c, d);
            }
       }
       return 0; 
   }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d){
        for(int i=0; i<V; i++) {
            vis[i] = 0;
        }
        dfs(c, adj, c, d);
        return (!vis[d]);
    }
};