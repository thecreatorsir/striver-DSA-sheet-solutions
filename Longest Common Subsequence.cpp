class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int x = size(text1);
        int y = size(text2);
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[x][y];
    }
};