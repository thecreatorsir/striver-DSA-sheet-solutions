class Solution
{
public:
    void solve(int ind,int sum,vector<int> &arr,int N,vector<int> &subset){
        if(ind == N){
            subset.push_back(sum);
            return;
        }
        //take
        solve(ind+1,sum+arr[ind],arr,N,subset);
        //don't take
        solve(ind+1,sum,arr,N,subset);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {   vector<int> subset;
        solve(0,0,arr,N,subset);
        return subset;
    }
};