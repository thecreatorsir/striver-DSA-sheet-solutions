vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    int n = A.size();
    vector<int> res(n,-1);
    for(int i=0;i<n;i++){
        while(!s.empty() and s.top()>=A[i]){
            s.pop();
        }
        if(!s.empty()) res[i]=s.top();
        s.push(A[i]);
    }
    return res;
}
