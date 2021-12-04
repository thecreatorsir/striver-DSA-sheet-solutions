class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        int sums[n] = {0};
        sums[0] = nums[0];
        map<int,int> mp;
        for(int i=1;i<n;i++)
            sums[i] = sums[i-1] + nums[i];
        
        int len = 0,ans=0;
        for(int i=0;i<n;i++){
            if(mp.find(sums[i])!=mp.end()){
                len = i-mp[sums[i]];
            }else if(sums[i]==0){
                len = i+1;
            }else{
                mp[sums[i]]=i;
            }
            ans = max(len,ans);
        }
        return ans;
    }
};