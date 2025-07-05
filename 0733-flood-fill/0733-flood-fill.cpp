class Solution {
public:
    bool isSafe(int r ,int c, int m, int n){
        return r<m && c<n && r>=0 && c>=0;
    }
    void helper(vector<vector<int>>& image, int sr, int sc, int color,int x){
        image[sr][sc]=color;
        vector<int> rows={1,-1,0,0};
        vector<int> cols={0,0,1,-1};
        for(int k=0;k<4;k++){
            int r = sr + rows[k];
            int c = sc + cols[k];
            if(isSafe(r,c,image.size(),image[0].size()) && image[r][c]==x){
                helper(image,r,c,color,x);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x=image[sr][sc];
        if(x==color)return image;
        helper(image,sr,sc,color,x);
        return image;   
    }
};