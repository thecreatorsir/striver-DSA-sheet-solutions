bool isPossible(int node,bool graph[101][101],int color[],int col,int n){
    for(int i=0;i<n;i++){
        if(i!=node and graph[i][node]==1 and color[i]==col){
            return false;
        }
    }
    return true;
}


bool solver(int node,bool graph[101][101],int color[],int n,int m){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isPossible(node,graph,color,i,n)){
            color[node] = i;
            if(solver(node+1,graph,color,n,m)) return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V] = {0};
    if(solver(0,graph,color,V,m)) return true;
    return false;
}