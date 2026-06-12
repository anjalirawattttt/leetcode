class Solution {
public:
    int trap(vector<int>& height) {
        int rain = 0;
        int n = height.size();

        vector<int> leftMax(n,-1);
        vector<int> rightMax(n,-1);
        int maxi=-1;
        for(int i=0;i<n;i++){
            leftMax[i]=maxi;
            maxi=max(maxi,height[i]);
        }
        maxi=-1;
        for(int i=n-1;i>=0;i--){
            rightMax[i]=maxi;
            maxi=max(maxi,height[i]);
        }

        for(int i=0;i<n;i++){
            int mini=min(leftMax[i],rightMax[i]);
            if(mini>height[i])rain+=mini-height[i];
        }

        return rain;    
    }
};