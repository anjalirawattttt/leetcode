class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=nums[0];
        int l=0,r=nums.size()-1,mid;
        while(l<=r){
            mid = l + (r-l)/2 ;
            ans=min(ans,nums[mid]);
            if(l==r)break;

            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }

        }
        return ans;

        
    }
};