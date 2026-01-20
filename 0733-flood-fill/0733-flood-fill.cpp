class Solution {
public:
    vector<int> rows={0,0,1,-1};
    vector<int> cols={1,-1,0,0};
    void dfs(int i,int j,vector<vector<int>> &image,int color,int pc){
        image[i][j]=color;
        for(int k=0;k<4;k++){
            int r=i+rows[k];
            int c=j+cols[k];
            if(r>=0 && c>=0 && r<image.size() && c<image[0].size() && image[r][c]==pc){
                dfs(r,c,image,color,pc);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        if(color==image[sr][sc])return image;
        dfs(sr,sc,image,color,image[sr][sc]);
        return image;   
    }
};