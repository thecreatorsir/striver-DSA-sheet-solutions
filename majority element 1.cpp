//O(n) space complexity
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto x:mp){
            if(x.second > n/2){
                return x.first;
            }
        }
        return -1;
    }
};

//O(1) space complexity
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int candidate = 0;
        for(int i=0;i<n;i++){
            if(count==0){
                candidate = nums[i];
            }
            count = candidate==nums[i]?count+1:count-1;
        }
        return candidate;
    }
};