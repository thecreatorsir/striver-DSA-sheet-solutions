vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        queue<int> q;
        vector<int> vis(V+1);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto x:adj[curr]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
      return ans;
}