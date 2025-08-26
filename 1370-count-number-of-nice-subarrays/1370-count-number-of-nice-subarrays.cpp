class Solution {
public:
    int help(vector<int>&nums,int k){
        //no of subarrays with <=k odd nos
        if(k<0)return 0;
        int l=0,r=0,n=nums.size();
        int odds=0,ans=0;
        while(r<n){
            if(nums[r]%2!=0)odds++;
            while(odds>k){
                if(nums[l]%2!=0)odds--;
                l++;
            }
            if(odds<=k)ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};