class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                pq.push(nums[i]); 
            }else{
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        } 
        
        return pq.top();
    }
};