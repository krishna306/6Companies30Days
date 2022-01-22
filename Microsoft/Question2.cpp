class Solution {
    bool isCyclic(vector<vector<int>>& adj,vector<int>& visited,int curr){
        if(visited[curr]==2){
            return true;
        }
        visited[curr] = 2;
        for(int i=0;i<adj[curr].size();++i){
            if(visited[adj[curr][i]]!=1){
                if(isCyclic(adj,visited,adj[curr][i])){
                    return true;
                }
            }
        }
        visited[curr] = 1;
        return false;
    }
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> adj(N);
        for(int i=0;i<prerequisites.size();++i){
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> visited(N,0);
        for(int i=0;i<N;++i){
            if(visited[i]==0){
                if(isCyclic(adj,visited,i)){
                    return false;
                }
            }
        }
        return true;
	}
};