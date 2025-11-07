class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int> m;
        // m[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum%k==0)ans++;
            for(auto &p:m){
                int num=p.first;
                int freq=p.second;
                if((sum-num)%k==0)ans+=freq;
            }
            
            m[(sum)%k]++;   
        }
        return ans;

    }
};