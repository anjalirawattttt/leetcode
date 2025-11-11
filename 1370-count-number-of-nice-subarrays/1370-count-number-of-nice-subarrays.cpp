class Solution {
public:
    int help(vector<int>& nums,int k){
        if(k<0)return 0;
        int l=0,r=0,n=nums.size();
        int ans=0,count=0;
        while(r<n){
            if(nums[r]%2==1)count++;
            while(l<n && count>k){
                if(nums[l]%2==1)count--;
                l++;
            }
            if(count<=k)ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);    
    }
};