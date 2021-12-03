class Solution {
public:
    int merge(vector<int>& arr,int temp[],int left,int mid,int right)
    {
        int count=0;
        int i = left;
        int j = mid;
        int k = left;
        //main code 
        for(i=left;i<mid;i++){
            while(j<=right and arr[i] > 2LL*arr[j]){
                j++;
            }
            count += (j - mid);
        }
        //rest same as merge sort
        i = left,j=mid;
        while((i <= mid-1) && (j <= right)){
            if(arr[i] <= arr[j]){
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }

        while(i <= mid - 1)
            temp[k++]=arr[i++];

        while(j <= right)
            temp[k++]=arr[j++];

        for(i = left ; i <= right ; i++)
            arr[i] = temp[i];

        return count;
    }

    int merge_Sort(vector<int>& arr,int temp[],int left,int right)
    {
        int mid,count = 0;
        if(right > left)
        {
            mid = (left + right)/2;

            count += merge_Sort(arr,temp,left,mid);
            count += merge_Sort(arr,temp,mid+1,right);

            count += merge(arr,temp,left,mid+1,right);
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int temp[n];
        return merge_Sort(nums,temp,0,n-1);
    }
};                                                                          
                                        