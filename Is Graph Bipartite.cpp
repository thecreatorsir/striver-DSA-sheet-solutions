//dfs approach
class Solution {
public:
    bool colorIt(int parent,int clr,vector<vector<int>>& graph,vector<int> &color){
        color[parent] = clr;
        for(auto x:graph[parent]){
            if(color[x]==0){
                if(!colorIt(x,-clr,graph,color)) return false;
            }else{
                if(color[x]==clr){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),0);
        for (int i = 0; i < graph.size(); i++){
            if(color[i]==0){
                if(!colorIt(i,1,graph,color)) return false;
            }
        }
        return true;
    }
};

//bfs approach
class Solution {
public:
    bool colorIt(vector<vector<int>>& graph,vector<int> &col,int node){
        queue<int>q;
        q.push(node); 
        col[node] = 1; 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop();

            for(auto x : graph[node]) {
                if(col[x] == 0) {
                    col[x] = -1*col[node]; 
                    q.push(x); 
                } else if(col[x] == col[node]) {
                    return false; 
                }
            }
        }
    return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        for(int i = 0;i<n;i++) {
            if(color[i] == 0) {
                if(!colorIt(graph, color,i)) {
                    return false;
                }
            }
        }
        return true; 
    }
};