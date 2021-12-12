// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        int n = str.length();
        bool dp[n][n];
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                if(g==0){
                  dp[i][j] = true;
                }
                else if(g==1){
                  dp[i][j] = str[i]==str[j];
                }
                else{
                  if(str[i]==str[j] and dp[i+1][j-1]){ 
                      dp[i][j]=true;
                  }
                  else{ 
                  dp[i][j] = false;
                  }
                }
            }
        }
        int dp1[n] = {0};
        for(int j=1;j<n;j++){
            if(dp[0][j]){
                dp1[j] = 0;
            }else{
                int mn = INT_MAX;
                // based on suffix, last se palindromic siffix check karenge
                for(int i=j;i>=0;i--){
                    if(dp[i][j]){
                        mn = min(mn,dp1[i-1]);
                    }
                }
                dp1[j] = mn+1;
            }
        }
       return dp1[n-1]; 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends