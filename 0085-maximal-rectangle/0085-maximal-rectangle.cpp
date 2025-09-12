class Solution {
public:
    int maxArea(vector<int>& heights){
        int n=heights.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> s;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i])s.pop();
            pse[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i])s.pop();
            nse[i]=s.empty()?n:s.top();
            s.push(i);
        }

        for(int i=0;i<n;i++){
            int width=nse[i]-pse[i]-1;
            ans=max(ans,heights[i]*width);
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