class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        
        vector<vector<int>> ans;
        int start = intervals[0][0],end=intervals[0][1]; 
        // taking first inteval always
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end and intervals[i][1] > end ){
                end = intervals[i][1];
            }else if(intervals[i][0]>end){
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
         ans.push_back({start,end});
        return ans;
    }
};