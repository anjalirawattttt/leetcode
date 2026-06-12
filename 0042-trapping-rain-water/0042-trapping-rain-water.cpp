class Solution {
public:
    int trap(vector<int>& height) {
        int rain = 0;
        int n = height.size();

        
        vector<int> rightMax(n,-1);
        int maxi=-1;
        for(int i=n-1;i>=0;i--){
            rightMax[i]=maxi;
            maxi=max(maxi,height[i]);
        }
        maxi=-1;
        for(int i=0;i<n;i++){
            int mini=min(maxi,rightMax[i]);
            if(mini>height[i])rain+=mini-height[i];
            maxi=max(maxi,height[i]);
        }

        

        return rain;    
    }
};