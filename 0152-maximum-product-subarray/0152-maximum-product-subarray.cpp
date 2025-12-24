class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long minProduct=nums[0];
        long long maxProduct=nums[0];
        long long ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(minProduct,maxProduct);
            }
            maxProduct=max((long long)nums[i],nums[i]*maxProduct);
            minProduct=min((long long)nums[i],nums[i]*minProduct);
            ans=max(ans,maxProduct);
        }
        return (int)ans;
    }
};