class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> prefix(n);
        int product=1;
        for(int i=0;i<n;i++){
            prefix[i]=product;
            product*=nums[i];
        }
        product=1;
        vector<int> suffix(n);
        for(int i=n-1;i>=0;i--){
            suffix[i]=product;
            product*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;    
    }
};