class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int localMax = nums[0],globalMax = nums[0];
        for(int i=1;i<nums.size();i++){
            localMax = max(localMax+nums[i],nums[i]);
            globalMax = max(globalMax,localMax);
        }
        return globalMax;
    }
};