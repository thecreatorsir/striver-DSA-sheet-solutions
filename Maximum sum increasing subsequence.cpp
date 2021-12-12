int maxSumIS(int nums[], int n)  
	    {
        int local_max=nums[0],global_max=nums[0];
        vector<int> dp(n+1,0);
       
           dp[0] = nums[0]; 
           for(int i=1;i<n;i++){
               local_max = 0;
               for(int j=0;j<i;j++){
                   if(nums[i]>nums[j]){
                       local_max = max(local_max,dp[j]);
                   }
               }
               //this will contair maximum  value so far
                dp[i] = local_max+nums[i];
                global_max = max(global_max,dp[i]); 
           }
        return global_max;
    }