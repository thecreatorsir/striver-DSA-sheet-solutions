class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int helper(int f,int eggs){
        if(eggs==1 || f<=1)
            return f;
     
        if(dp[f][eggs]!=-1)
            return dp[f][eggs];
        int mn = INT_MAX;
        
        for(int k=1;k<=f;k++){
            int brek = dp[f][eggs] = helper(k-1,eggs-1);
            int notbrek = dp[f][eggs] = helper(f-k,eggs);
            
            int temp = 1 + max(brek,notbrek);
            
            mn = min(mn,temp);
        }
        return dp[f][eggs] = mn;
    }
    int eggDrop(int n, int k) 
    {   memset(dp,-1,sizeof(dp));
        return helper(k,n);
    }
};
