class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int currMax=nums[0],currMin=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0)swap(currMax,currMin);
            currMax=max((long long)nums[i],currMax*(long long)nums[i]);
            currMin=min((long long)nums[i],currMin*(long long)nums[i]);
            ans=max(ans,(int)currMax);
        }
        return ans;   
    }
};