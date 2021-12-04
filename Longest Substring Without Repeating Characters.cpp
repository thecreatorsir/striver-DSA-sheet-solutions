//here we are putting the next index in the map corresponding to the every char because whenever we found a repeating char we will start from next to its previously repeating char.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_map<char,int> mp;
        for(int i=0,j=0;j<size(s);j++){
            if(mp.count(s[j])>0)
                i = max(mp[s[j]],i);
            result = max(result,j-i+1);
            mp[s[j]] = j+1; 
        }
         return result;
    }
};