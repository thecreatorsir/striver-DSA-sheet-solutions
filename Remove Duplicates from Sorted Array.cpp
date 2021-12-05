class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        if(n==0) return 0;
        int count=1;
        while(j<n-1){
            if(nums[j]!=nums[j+1]) nums[++i]=nums[j+1],count++;
            j++;
        }
        return count;
    }
};