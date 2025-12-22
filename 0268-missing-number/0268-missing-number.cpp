class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorAll=0;
        int n=nums.size();
        for(int i=0;i<=n;i++){
            xorAll^=i;
        }
        for(int i=0;i<n;i++){
            xorAll^=nums[i];
        }
        return xorAll;    
    }
};