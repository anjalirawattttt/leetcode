class Solution {
public:
    int numSubarrayless(vector<int>& nums,int goal){
        if(goal<0)return 0;
        int l=0,r=0,n=nums.size();
        int ans=0,sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            if(sum<=goal){
                ans+=r-l+1;
            }

            r++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarrayless(nums,goal) - numSubarrayless(nums,goal-1);
    }
};