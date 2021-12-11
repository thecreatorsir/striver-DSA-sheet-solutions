void sortUtil(int start,vector<int> adj[],bool visited[],stack<int> &temp){
	    visited[start] = true;
	    for(auto x:adj[start]){
	        if(!visited[x]){
	            sortUtil(x,adj,visited,temp);
	        }
	    }
	    temp.push(start);
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    bool visited[V];
	    vector<int> v;
	    stack<int> s;
	    fill(visited,visited+V,false);
	   for (int i = 0; i < V; i++)
        if (!visited[i])
          sortUtil(i,adj, visited,s);
          
	    while(!s.empty()){
	        v.push_back(s.top());
	        s.pop();
	    }
	    
	    return v;
	}