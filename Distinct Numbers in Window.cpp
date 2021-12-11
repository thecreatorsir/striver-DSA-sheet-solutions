vector<int> Solution::dNums(vector<int> &a, int k) {
    map<int,int> mp;
    int dcount = 0;
    vector<int> ans;
    for(int i=0;i<k;i++){
        if(mp[a[i]]==0){
            dcount++;
        }
        mp[a[i]]++;
    }
    ans.push_back(dcount);
    for(int i=k;i<a.size();i++){
        
        if(mp[a[i-k]]==1){
            dcount--;
        }
        mp[a[i-k]]--;
        if(mp[a[i]]==0){
            dcount++;
        }
        mp[a[i]]++;
    ans.push_back(dcount);
    }
return ans;
}
