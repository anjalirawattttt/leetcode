class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixProd(n,1);
        vector<int> suffixProd(n,1);
        int prod=1;
        for(int i=n-1;i>=0;i--){
            suffixProd[i]=prod;
            prod*=nums[i];
        }
        prod=1;
        for(int i=0;i<n;i++){
            prefixProd[i]=prod;
            int temp=nums[i];
            nums[i]=prefixProd[i]*suffixProd[i];
            prod*=temp;
        }
        return nums;
    }
};