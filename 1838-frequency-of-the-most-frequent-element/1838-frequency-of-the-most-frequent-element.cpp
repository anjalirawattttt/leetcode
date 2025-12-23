class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int len=0;
        long long sum=0;
        int l=0,r=0,n=nums.size();
        while(r<n){
            sum+=nums[r];
            if( ((long long)(r-l+1)*nums[r])-sum > k){
                sum-=nums[l];
                l++;
            }
            if( ((long long)(r-l+1)*nums[r]-sum) <= k)len=max(len,r-l+1);
            r++;
        }
        return len;  
    }
};