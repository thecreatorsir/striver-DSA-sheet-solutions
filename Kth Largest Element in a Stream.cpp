class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int k_;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i<k){
                pq.push(nums[i]);
            }
            else{
                if(nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);  
                }
            }
        }
        k_ = k;
    }
    
    int add(int val) {
        if(!pq.empty()){
            if(pq.size()<k_){
                pq.push(val);
            }
            else{
                if(val > pq.top()){
                    pq.pop();
                    pq.push(val);  
                }
            }
        }else{
            pq.push(val);
        }
        return pq.top();
    }
};
