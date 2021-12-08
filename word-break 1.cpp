//recursive method
int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}

bool wordBreak(string str)
{
    int size = str.size();
 
    // Base case
    if (size == 0)  return true;
 
    // Try all prefixes of lengths from 1 to size
    for (int i=1; i<=size; i++)
    {
        if (dictionaryContains( str.substr(0, i) ) &&
            wordBreak( str.substr(i, size-i) ))
            return true;
    }
    return false;
}

//dp solution
class Solution
{
public:
    int wordBreak(string s, vector<string> &wordDict) {
        int len = s.length();
            vector<bool> dp(len+1,false);
            dp[0] = true;
            
            for(int i=1;i<=len;i++){
              //check for the left side
                for(int j=0;j<i;j++){
                  //if exists look for the right side
                   if(dp[j] and find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                    dp[i]=true;   
                   }              
                }
            }
    return dp[len];
    }
};