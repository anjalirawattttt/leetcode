class Solution {
public:
    bool isSafe(int r,int c,int n,int m){
        return r<n && r>=0 && c<m && c>=0;
    }

    void dfsRec(vector<vector<int>>& image,int x,int color,int sr,int sc){    
         
        vector<int> rows={0,0,1,-1};
        vector<int> cols={1,-1,0,0};
        for(int k=0;k<4;k++){
                int r = sr + rows[k];
                int c = sc + cols[k];
                if(isSafe(r,c,image.size(),image[0].size()) && image[r][c]==x){
                    image[r][c]=color;
                    dfsRec(image,x,color,r,c);
                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x=image[sr][sc];
        if(x==color)return image;
        image[sr][sc]=color;
        dfsRec(image,x,color,sr,sc);
        return image;
    }
};