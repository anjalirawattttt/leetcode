class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int n=heights.size();
        vector<int> prevSmaller(n,-1); 
        vector<int> nextSmaller(n);

        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i])s.pop();
            prevSmaller[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i])s.pop();
            nextSmaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        for(int i=0;i<n;i++){
            int width=nextSmaller[i]-prevSmaller[i]-1;
            int height=heights[i];
            ans=max(ans,width*height);
        }
        return ans;
    }
};