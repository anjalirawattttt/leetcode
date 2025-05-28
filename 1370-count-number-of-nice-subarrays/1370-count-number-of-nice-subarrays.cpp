class Solution {
public:
    int helper(vector<int>& nums, int k){
        int ans=0,sum=0;
        int l=0,r=0,n=nums.size();

        while(r<n){
            sum+=nums[r]%2;
            while(sum>k){
                sum-=nums[l]%2;
                l++;
            }
            if(sum<=k){
                ans+=r-l+1;
            }
            r++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);       
    }
};