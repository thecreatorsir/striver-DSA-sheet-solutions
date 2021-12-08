class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m) return kthElement(arr2,arr1,m,n,k);
        
        //taking minimum of something from arr1 if k greater then arr2
        int l = max(0,k-m);
        // taking maximum if n element from arr1
        int r = min(k,n);
        while(l<=r){
            int cut1 = (l+r)/2;
            int cut2 =  k - cut1;
            
            int l1 = cut1==0?INT_MIN:arr1[cut1-1];
            int l2 = cut2==0?INT_MIN:arr2[cut2-1];
            int r1 = cut1==n?INT_MAX:arr1[cut1];
            int r2 = cut2==m?INT_MAX:arr2[cut2];
            
            if(l1<=r2 and l2<=r1){
                return max(l1,l2);
            }else if(l1>r2){
                r = cut1-1;
            }else{
                l=cut1+1;
            }
        }
        return -1;
    }
};