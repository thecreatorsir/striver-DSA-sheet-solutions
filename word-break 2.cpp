class Solution {
    vector<string> ans;
public:
    void helper(string s,vector<string> &w,string temp){
        int size = s.size();
        if(size==0){
            //removing last extra sapce
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        for(int i=1;i<=size;i++){
            string left = s.substr(0,i);
            if(find(w.begin(),w.end(),left)!=w.end()){
                helper(s.substr(i,size-i),w,temp+left+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string temp = "";
        helper(s,wordDict,temp);
        return ans;
    }
};