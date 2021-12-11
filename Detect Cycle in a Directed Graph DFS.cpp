bool cycle_helper(int node,vector<vector<int>>&graph,vector<bool> &visited,vector<bool> &recstack){
       visited[node] = true;
       recstack[node] = true;
       
       for(auto p:graph[node]){
           if(recstack[p]){
               return true;
           }else if(!visited[p] and cycle_helper(p,graph,visited,recstack)){
                   return true;
            }
        }
       recstack[node]=false;
       return false;
   }