class Solution {
public:
    void make_zero(vector<vector<int>>& matrix,int i,int j,int n,int m){
        // make row and col 0
        for(int k=0;k<n;k++){
            matrix[k][j]=0;
        }
         for(int k=0;k<m;k++){
            matrix[i][k]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        //make copy of current matrix
        
        vector<vector<int>> cpy = matrix;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(cpy[i][j]==0){
                    make_zero(matrix,i,j,n,m);
                }
            }
        }
    }
};