int counter(int mid,vector<int> &A,int m){
    int l = 0;
    int h = m-1;
    while(l<=h){
        int md = (l+h)>>1;
        if(A[md]>mid){
            h=md-1;
        }else{
            l = md+1;
        }
    }
    return l;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int left = INT_MIN;
    int right = INT_MAX;
    
    int n = A.size();
    int m = A[0].size();
    while(left<=right){
        int mid = (left+right)>>1;
        int count  = 0;
        for(int i=0;i<n;i++){
            count+=counter(mid,A[i],m);
        }
        if(count > (n*m)/2) right = mid-1;
        else left= mid+1; 
    }
    return left;
}
