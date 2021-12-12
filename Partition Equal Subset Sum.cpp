class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int N = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if(sum&1) return false;
        vector<vector<bool>> dp(N + 1, vector<bool>(sum/2 + 1));
        //initialisation
        for(int i=0;i<=N;i++)
            dp[i][0] = true;
        
    
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum/2;j++){
                if(j>=arr[i-1]){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                  }else{
                    dp[i][j] = dp[i-1][j];  
                }
            }
        }
        return dp[N][sum/2];
    }
};