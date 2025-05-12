class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        sort(nums.begin(),nums.end());
        int ans=INT_MIN;
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])continue;

            if(nums[i]==nums[i-1]+1)count++;
            else count=1;
            ans=max(ans,count);
        }
        ans=max(ans,count);
        return ans;
    }
};