class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int n=height.size();
        vector<int> leftMax(n);
        int left=0,right=0;
        vector<int> rightMax(n);

        for(int i=0;i<n;i++){
            leftMax[i]=left;
            left=max(left,height[i]);
        }


        for(int i=n-1;i>=0;i--){
            rightMax[i]=right;
            right=max(right,height[i]);
        }


        for(int i=0;i<n;i++){
            int temp=min(leftMax[i],rightMax[i]) -height[i];
            if(temp>0){
                water+=temp;
            }
        }

        


        return water;
    }
};