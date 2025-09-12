class Solution {
public:
    int maxArea(vector<int>& heights){
        int n=heights.size();
        stack<int> s;
        int ans=0;
        for(int i=0;i<=n;i++){
           int height=(i==n)?0:heights[i];
           while(!s.empty() && height<heights[s.top()]){
                int h=heights[s.top()];
                s.pop();
                int width=s.empty()?i:i-s.top()-1;
                ans=max(ans,h*width);
           }
           s.push(i); 
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> heights(n,0);
        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0')heights[j]=0;
                else heights[j]++;
            }
            int area=maxArea(heights);
            ans=max(ans,area);  
        }
        return ans;   
    }
};