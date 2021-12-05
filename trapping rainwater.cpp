class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) return 0; 
        int left[30001] = {0};
        int right[30001] = {0};
        
        left[0] = height[0];
        right[n-1] = height[n-1];
        
        for(int i=1;i<n;i++)
            left[i] = max(left[i-1],height[i]);
        for(int i=n-2;i>=0;i--)
            right[i] = max(right[i+1],height[i]);
        int ans = 0;
        for(int i=1;i<n-1;i++)
            ans +=min(left[i],right[i])-height[i];
        return ans;
    }
};

//O(1) space Solution
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size(); 
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        
        while(left<=right){
            
            if(height[left]<=height[right]){

                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                
                left++;
            }
            else{

                if(height[right]>=maxright) maxright= height[right];
                else res+=maxright-height[right];
                
                right--;
            }
        }
        return res;
    }
};