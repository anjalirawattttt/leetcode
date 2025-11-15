class Solution {
public:
    int findLargestAreaInHistogram(vector<int> &heights){
        int n=heights.size();
        stack<int> s;
        int maxArea=0;
        for(int i=0;i<=n;i++){
            int height = i==n ? 0 : heights[i];
            while(!s.empty() && heights[s.top()]>height){
                int h=heights[s.top()];
                s.pop();
                //prev smaller element
                int w = s.empty() ? i : i-s.top()-1;
                maxArea=max(maxArea,h*w);
            }
            s.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> currRow(n,0);
        int maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0')currRow[j]=0;
                else currRow[j]++;
            }
            int area=findLargestAreaInHistogram(currRow);
            cout<<area<<endl;
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};