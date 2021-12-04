int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int currXor = 0,count = 0;

    for(int i=0;i<A.size();i++){
        currXor^=A[i];
        if(currXor==B){
            count++;
        }
        if(mp.find(currXor^B)!=mp.end()){
            count+=mp[currXor^B];
        }
        mp[currXor]++;
    }
    return count;
}