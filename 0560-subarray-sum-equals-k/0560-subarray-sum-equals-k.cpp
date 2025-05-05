class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,sum=0;
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int prefixSum=sum-k;
            if(prefixSum==0)ans++;
            if(m.find(prefixSum)!=m.end())ans+=m[prefixSum];
            m[sum]++;
        }
        return ans;        
    }
};