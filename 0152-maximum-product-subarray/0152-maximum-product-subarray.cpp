class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long prod_max=nums[0],prod_min=nums[0];\
        long long ans=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0)swap(prod_max,prod_min);
            prod_max=max((long long)nums[i],prod_max*nums[i]);
            prod_min=min((long long)nums[i],prod_min*nums[i]);
            ans=max(ans,prod_max);
        }  
        return (int)ans;  
    }
};