class Solution {
public:
    int help(vector<int>&nums ,int goal){
        //no of subarrays with sum<=goal 
        //no of subarrays with sum<=goal-1  
        if(goal<0)return 0;

        int l=0,r=0,n=nums.size(),sum=0;
        int ans=0;
        while(r<n){
            sum+=nums[r];
            while(l<n && sum>goal){
                sum-=nums[l];
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return help(nums,goal)-help(nums,goal-1); 
    }
};