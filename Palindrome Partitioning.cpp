class Solution {
public:
     bool palindrome(string pre,int start,int end){
        int l = start;
        int r = end;
        while(l<r){
            if(pre[r]!=pre[l]) return false;
            l++;r--;
        }
        return true;
    }
    void solver(int ind,vector<vector<string>> &ans,vector<string> temp,string &s){
        //base case
        if(ind>=size(s)){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(palindrome(s,ind,i)){
                temp.push_back(s.substr(ind, i - ind + 1));
                solver(i+1,ans,temp,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solver(0,ans,temp,s);
        return ans;
    }
};