class Solution
{
    public:
    static bool cmp(pair<int,int>a,pair<int,int> b){
        if(a.second<b.second) return true;
        if(a.second==b.second) return a.first < b.first;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int count = 1;
        int last = v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first > last){
                last = v[i].second;
                 count++;
            }
        }
        return count;
    }
};