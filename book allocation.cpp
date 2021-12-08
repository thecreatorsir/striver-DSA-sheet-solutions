    bool possible(vector<int> &book, int m,int n,int mid){
        int curr_stu = 1;
        int pages_count = 0;
        for(int i=0;i<n;i++){
                if(pages_count + book[i] > mid){
                    curr_stu++;
                    pages_count=book[i];
                    if(pages_count > mid) return false;
                }
                else{
                    pages_count += book[i];
                }
        }
        if(curr_stu<=m) return true;
        return false;
    }
    int solver(vector<int> &A, int B,int n,int total){
        if(B > A.size()) return -1; 
        int low = A[n-1];
        int high = total;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(possible(A,B,n,mid)){
                ans=mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    int Solution::books(vector<int> &A, int B) {
        int n = A.size();
        int total = 0;
        for(auto x:A){
            total+=x;
        }
        return solver(A,B,n,total);
    }


