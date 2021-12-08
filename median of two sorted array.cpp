class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        if (m > n) {
            return findMedianSortedArrays(B, A);
        } 
        int l = 0, r = m;
        while (l <= r) {   
            int p1 = (l+r)/2;
            int p2 = (m+n+1)/2-p1;
            
            int mxL1 = p1==0?INT_MIN:A[p1-1];
            int mxL2 = p2==0?INT_MIN:B[p2-1];
            int mnR1 = p1==m?INT_MAX:A[p1];
            int mnR2 = p2==n?INT_MAX:B[p2];
            
            if(mxL1 <= mnR2 and mxL2 <= mnR1){
                return (m+n)%2?max(mxL1,mxL2):(max(mxL1,mxL2) + min(mnR1,mnR2))/2.0;
            }
            
            else if(mxL1 > mnR2){
                r = p1-1;
            }else{
                l = p1+1;
            }
        }
        return 0.0;
    }
};