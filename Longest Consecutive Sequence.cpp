//hashing based solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int n = nums.size();
        for(int i=0;i<n;i++) mp[nums[i]] = false;
        
        for(int i=0;i<n;i++)
            if(mp.find(nums[i]-1)==mp.end())
                mp[nums[i]] = true;
        
        int len  = 0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]){
                 int count = 1;
                while(mp.find(nums[i]+count)!=mp.end()){
                    count++;
                }
                len = max(len,count);
            }
        }
        return len;
    }
};

//sorting based solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
              return 0;
        sort(nums.begin(),nums.end());
        int count=1;
        int ans=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]+1)
                count++;
        
            else if(nums[i]==nums[i-1])
                continue;
            else
                count=1;
            ans=max(ans,count);
                
        }
        return ans;
        
    }
};    