class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        int ans=0;
        for(int i=0;i<=n;i++){
           int height=(i==n)?0:heights[i];
           while(!s.empty() && heights[s.top()]>height){
                int h=heights[s.top()];
                s.pop();
                int width=s.empty()?i:i-1-s.top();
                ans=max(ans,h*width);
           }
           s.push(i); 
        }
        return ans;
            
    }
};