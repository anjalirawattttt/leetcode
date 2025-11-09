class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && heights[s.top()]>=heights[i])s.pop();
            pse[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        s.push(n);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=n && heights[s.top()]>=heights[i])s.pop();
            nse[i]=s.top();
            s.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int height=heights[i];
            int width=nse[i]-pse[i]-1;
            maxArea=max(maxArea,height*width);
        }
        return maxArea;
            
    }
};