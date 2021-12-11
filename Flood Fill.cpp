class Solution {
    public:
    int n = 0;
    int m = 0;
    void helper(vector<vector<int>>& image,int i,int j,int color,int curr){
        if(i>=n || i<0 || j>=m || j<0 || image[i][j]!=curr){
            return;
        }
        image[i][j] = color;
        helper(image,i+1,j,color,curr);
        helper(image,i,j+1,color,curr);
        helper(image,i-1,j,color,curr);
        helper(image,i,j-1,color,curr);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {       
        if(image[sr][sc]==newColor) return image;
        n = image.size();
        m = image[0].size();
        helper(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};