class Solution {
public:
    int help(vector<int> hist){
        int n = hist.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int height = (i == n) ? 0 : hist[i];
            while (!st.empty() && height < hist[st.top()]) {
                int h = hist[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> hist(c,0);
        int maxArea=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1') hist[j]++;
                else hist[j]=0;
            }
            int area=help(hist);
            maxArea=max(maxArea,area);
        } 
        return maxArea;
    }
};