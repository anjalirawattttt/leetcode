class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int ans=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};