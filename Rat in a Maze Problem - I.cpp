class Solution{
    vector<string> ans;
    public:
    void solver(vector<vector<int>> &vis,vector<vector<int>> &m,int n,
    int i,int j,string temp){
        if(i<0 || i>n-1 || j<0 || j>n-1 || vis[i][j] || m[i][j]==0){
            return;
        }
        if(i==n-1 and j==n-1){
            ans.push_back(temp);
            return;
        }
        vis[i][j] = 1;
        solver(vis,m,n,i+1,j,temp+"D");
        solver(vis,m,n,i,j-1,temp+"L");
        solver(vis,m,n,i,j+1,temp+"R");
        solver(vis,m,n,i-1,j,temp+"U");
        vis[i][j] = 0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> visited(n,vector<int>(n,0));
        string temp = ""; 
        solver(visited,m,n,0,0,temp);
        return ans;
    }
};