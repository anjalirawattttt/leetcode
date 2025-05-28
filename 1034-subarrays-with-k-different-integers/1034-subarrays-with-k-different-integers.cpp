class Solution {
public:
    int helper(vector<int>& nums, int k){
        if(k<0)return 0;
        unordered_map<int,int> m;
        int l=0,r=0,n=nums.size();
        int ans=0;
        while(r<n){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]]==0)m.erase(nums[l]);
                l++;
            }
            if(m.size()<=k){
                ans+=r-l+1;    
            }
            r++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);    
    }
};