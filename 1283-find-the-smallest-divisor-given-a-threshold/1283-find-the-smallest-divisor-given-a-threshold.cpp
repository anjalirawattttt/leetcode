class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxEle=nums[0];
        for(int i=1;i<n;i++){
            maxEle=max(maxEle,nums[i]);
        }
        int l=1,r=maxEle;
        int ans=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int temp=0;
            for(int i=0;i<n;i++){
                temp+=(nums[i]+mid-1)/mid;
            }
            if(temp<=threshold){
                ans=mid;
                r=mid-1;
            }
            else{
                l = mid+1;
            }
        }  
        return ans;  
    }
};