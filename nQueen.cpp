class Solution {
    vector<vector<string>> ans;
public:
    bool isPossible(vector<vector<int>> &board,int i,int j,int n){
        //col check
        for(int row=0;row<i;row++){
            if(board[row][j]){ return false;}
        }
        //right diagonal
        int x = i-1;
        int y = j+1;
        while(x>=0 and y<n){
            if(board[x][y]){return false;}
            x--,y++;
        }
        // left diagonal
        x = i-1;
        y = j-1;
        while(x>=0 and y>=0){
            if(board[x][y]){return false;}
            x--,y--;
        }
        return true;
    }
    void solver(vector<vector<int>> &board,int i,int n){
        if(i==n){
            //creating op
            vector<string> s;
            for(int k=0;k<n;k++){
                string temp = "";
                for(int l=0;l<n;l++){
                    if(board[k][l]){
                        temp+="Q";
                    }else{
                        temp+=".";
                    } 
                }
                s.push_back(temp);
            }
            ans.push_back(s);
            return;
        }
        for(int j=0;j<n;j++){
            if(isPossible(board,i,j,n)){
                board[i][j]=1;
                solver(board,i+1,n);
            }
            board[i][j] = 0;
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        solver(board,0,n);
        return ans;
    }
};