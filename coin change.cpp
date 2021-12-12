int coinChange(vector<int>& coins, int sum) {
        int n= coins.size();
        int t[n+1][sum+1];
        
        //Initialization
        for(int i=0; i<sum+1; i++) t[0][i] = INT_MAX-1;
        for(int j=1; j<n+1; j++) t[j][0] = 0;
        
        //Unbounded Knapsack
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1] <= j){
                    t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return (t[n][sum] == INT_MAX || t[n][sum] == INT_MAX-1) ? -1 : t[n][sum];
    }