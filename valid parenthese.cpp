class Solution {
public:
    bool isValid(string s) {
        int i;
        int n=s.size();
        stack <char> s1;
        for(i=0;i<n;i++)
        {
         if(s1.empty())  s1.push(s[i]);
        else{
             if(s[i]=='{' || s[i]=='(' || s[i]=='[') s1.push(s[i]);
             else if((s[i]=='}' && s1.top()=='{')|| (s[i]==')' && s1.top()=='(') || (s[i]==']' && s1.top()=='[')) s1.pop();
             else s1.push(s[i]);
        }
    }
           if(s1.empty())
               return true;
            else return false;
        }
    
};