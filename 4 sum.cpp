class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int i,j,k,l;
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(i=0;i<n-3;i++){
            for(j=i+1;j<n-2;j++){
                k=j+1,l=n-1;
                 int sums = target - (arr[i] + arr[j]);
                while(k<l){
                    int sum = arr[k] + arr[l];
                    if(sum==sums){
                        s.insert({arr[i],arr[j],arr[k],arr[l]});
                        k++,l--;
                    }else if(sum<sums){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};