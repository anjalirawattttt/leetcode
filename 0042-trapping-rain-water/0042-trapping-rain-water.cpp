class Solution {
public:
    int trap(vector<int>& height) {
        int rain = 0;
        int n = height.size();

        int leftMax=0 , rightMax=0;
        int l=0 , r=n-1;
        while( l <= r ){
            if( l > 0 )leftMax=max(leftMax,height[l-1]);
            if( r < n-1 )rightMax=max(rightMax,height[r+1]);

            if(leftMax<rightMax){
                if(leftMax>height[l]) rain+= leftMax - height[l];
                l++;
            }
            else{
                if(rightMax>height[r]) rain+= rightMax - height[r];
                r--;
            }


        }

        return rain;    
    }
};