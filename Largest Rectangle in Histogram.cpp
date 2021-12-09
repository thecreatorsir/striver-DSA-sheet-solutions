class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int> s;
        int ans;
        int max_ans = 0; 
        int n = a.size();
        int i;  
        for(i=0;i<n;i++){
            while(!s.empty() and a[s.top()]>a[i]){
              int top=s.top();
                s.pop();
                ans=(s.empty())?a[top]*i:a[top]*(i-s.top()-1);
                   if(ans>max_ans){
                     max_ans = ans;
                    }
            }
            s.push(i);
        }

        //proccessing the bacha hua
        while (!s.empty())
        {   int top=s.top();
            s.pop();
            ans=(s.empty())?a[top]*i:a[top]*(i-s.top()-1);
            if(ans>max_ans){
                max_ans = ans;
            }
        }

        return max_ans;
    
    }
};