class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0],minp = nums[0],ans = nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(minp,maxp);
            minp = min(minp*nums[i],nums[i]);
            maxp = max(maxp*nums[i],nums[i]);
            ans = max(ans,maxp);
        }
        return ans;
    }
};