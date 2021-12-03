//O(n) space and O(n) time using map as done in the first part

//method - 2

//O(1) space and O(nlogn) time using sorting
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int lim = n/3,i=0;
        vector<int> v;
        sort(nums.begin(),nums.end());
        int cnt = 1;
        for(i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                cnt++;
            }else{
                if(cnt>lim)
                    v.push_back(nums[i]); 
                  cnt=1;
                }
            }
         if(cnt>lim)
            v.push_back(nums[i]);
                    
        return v;
    }
};

// method - 3

//O(1) space and O(n) time using map
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0,count2=0,candi1=0,candi2=0;
          vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==candi1)
                count1++;
            else if(nums[i]==candi2)
                count2++;
            else if(count1==0){
                 candi1=nums[i];
                 count1 = 1;
            }else if(count2==0){
                candi2=nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==candi1){
                count1++;
            }else if(nums[i]==candi2){
                count2++;
            }
        }
        if(count1 > n/3){
            ans.push_back(candi1);
        }
        if(count2 >n/3){
            ans.push_back(candi2);
        }   
        return ans;
    }
};