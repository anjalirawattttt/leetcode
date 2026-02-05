class Solution {
public:
    int lah(vector<int> &heights){
        int n=heights.size();
        vector<int> lse(n);
        vector<int> rse(n);

        stack<int> s;
        s.push(-1);

        for(int i=0;i<n;i++){
            while(s.top()!=-1 && heights[s.top()]>=heights[i])s.pop();
            lse[i]=s.top();
            s.push(i);
        }

        while(!s.empty())s.pop();
        s.push(n);

        for(int i=n-1;i>=0;i--){
            while(s.top()!=n && heights[s.top()]>=heights[i])s.pop();
            rse[i]=s.top();
            s.push(i);
        }

        for(int i=0;i<n;i++)cout<<lse[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)cout<<rse[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)cout<<heights[i]<<" ";
        cout<<endl;

        int maxArea=0;
        for(int i=0;i<n;i++){
            int height=heights[i];
            int width=rse[i]-lse[i]-1;
            int area=height*width;
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> height(n,0);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }  
                else{
                    height[j]=0;
                }  
            }
            int temp=lah(height);
            ans=max(ans,temp);
        }  
        return ans;  
    }
};