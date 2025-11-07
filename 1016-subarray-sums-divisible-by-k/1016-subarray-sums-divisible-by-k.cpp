class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int> m;
        m[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int mod=sum%k;
            if(mod<0)mod+=k;
            ans+=m[mod]; 
            m[mod]++;  
        }
        return ans;

    }
};