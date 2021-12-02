class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int i = 0,j=n-1;
        //swap row wize
        while(i<j){
            vector<int> temp = matrix[i];
            matrix[i] = matrix[j];
            matrix[j] = temp;
            i++,j--;
        }
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(i>j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
    }
};