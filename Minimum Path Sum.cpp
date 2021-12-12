// recusion with memo
class Solution {
public:
//     MEMO
    int m = 0;
    int n = 0;
    int solve(vector<vector<int>>& grid,vector<vector<int>>& memo,int i,int j){
        if(j==n-1 && i==m-1)return grid[i][j];
        if(j>=n || i>=m) return INT_MAX;
        if(memo[i][j]!=-1) return memo[i][j];
        int val1 = solve(grid,memo,i,j+1);  //Right
        int val2 = solve(grid,memo,i+1,j);  //Down
        int ans = min(val1,val2) + grid[i][j];
        memo[i][j] = ans;
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return solve(grid,memo,0,0);
    }
};

// dp solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
         for(int i=1;i<n;i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};