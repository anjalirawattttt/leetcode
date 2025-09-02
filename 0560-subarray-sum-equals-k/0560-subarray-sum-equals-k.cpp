class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> prefixSum;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k)ans++;
            ans+=prefixSum[sum-k];
            prefixSum[sum]++;
        }
        return ans;   
    }
};