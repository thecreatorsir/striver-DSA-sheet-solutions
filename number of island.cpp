class Solution {
public:
    void explore(vector<vector<char>>& grid,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!='1'){
            return;
        }
            
        grid[i][j] = '2';
        explore(grid,i-1,j,n,m);
        explore(grid,i,j-1,n,m);
        explore(grid,i+1,j,n,m);
        explore(grid,i,j+1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count  = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    explore(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};