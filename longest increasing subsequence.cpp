class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),local_max=1,global_max=1;
        int dp[2501] = {0};
       
           dp[0] = 1; 
           for(int i=1;i<n;i++){
               local_max = 0;
               for(int j=0;j<i;j++){
                   if(nums[i]>nums[j]){
                       local_max = max(local_max,dp[j]);
                   }
               }
               //this will contair maximum  value so far
                dp[i] = local_max+1;
                global_max = max(global_max,dp[i]); 
           }
        return global_max;
    }
};