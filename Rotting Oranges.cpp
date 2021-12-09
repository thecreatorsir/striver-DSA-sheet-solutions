class Solution {
public:
    vector<int> dx{1,-1,0,0};
    vector<int> dy{0,0,1,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int count1 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    count1++;
            }
        }
        int t=0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                pair<int,int> rem = q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    int x = rem.first + dx[i];
                    int y = rem.second + dy[i];
                    
                    if(x >=0 and y>=0 and x<n and y<m and grid[x][y]==1){
                        grid[x][y] = 2;
                        q.push({x,y});
                        count1--;
                    }
                }
            }
            if(!q.empty())
             t++;
        }
        //if someting remains
        if(count1!=0)
            return -1;
        
        return t;
    }
};