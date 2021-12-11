void dfs(vector<int> adj[],vector<int> &ans,vector<int> &vis,int curr){
        vis[curr] = 1;
        ans.push_back(curr);
        for(auto x:adj[curr]){
            if(!vis[x]){
                dfs(adj,ans,vis,x);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V+1);
        dfs(adj,ans,vis,0);
        return ans;
    }