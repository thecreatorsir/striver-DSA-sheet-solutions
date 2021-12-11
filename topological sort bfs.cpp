//cycle detection in directed graph
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>graph(n);
        vector<int> indegree(n);
        for(auto i : pre){
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int count = n;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            count--;
            for(auto x:graph[temp]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        return count==0?true:false;
    }
};