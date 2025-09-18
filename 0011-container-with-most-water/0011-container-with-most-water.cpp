class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int l=0,r=n-1;
        while(l<r){
            int h=min(height[l],height[r]);
            int w=r-l;
            ans=max(ans,h*w);
            if(height[l]<height[r]){
                l++;
            }
            else if(height[r]<height[l]){
                r--;
            }
            else{
                if(height[l+1]>height[r-1]){
                    l++;
                }  
                else if(height[r-1]>height[l+1]){
                    r--;
                } 
                else{
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};