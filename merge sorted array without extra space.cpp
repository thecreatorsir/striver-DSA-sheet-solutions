//method 1 : arr1 will contain all smaller element and arr2 will contain all larger element
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = 0;
        while(i>=0 and j<n){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
                j++;
            }else{
                i--;
            }
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        for(int i=m;i<m+n;i++){
            nums1[i] = nums2[i-m];
        }
    }
};

// method 2 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int m1 = m-1;
        int n2 = n-1;
        for(int i=m+n-1;i>=0;i--){
            int a = m1>=0?nums1[m1]:INT_MIN;
            int b = n2>=0?nums2[n2]:INT_MIN;
            
            if(a > b){
                nums1[i] = a;
                m1--;
            }else{
                nums1[i] = b;
                n2--;
            }
        }
    }
};
