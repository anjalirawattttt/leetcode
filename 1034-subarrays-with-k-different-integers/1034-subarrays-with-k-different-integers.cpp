class Solution {
public:
    int help(vector<int>& nums,int k){
        int l=0,r=0,n=nums.size();
        unordered_map<int,int> freq;
        int ans=0,diff=0;
        while(r<n){
            if(freq[nums[r]]==0)diff++;
            freq[nums[r]]++;
            while(diff>k){
                freq[nums[l]]--;
                if(freq[nums[l]]==0)diff--;
                l++;   
            }
            if(diff<=k)ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);   
    }
};