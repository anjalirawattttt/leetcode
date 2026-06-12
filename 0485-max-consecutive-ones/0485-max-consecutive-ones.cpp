class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int ones=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1)ones++;
            else ones=0;
            maxi=max(maxi,ones);
        }
        return maxi;    
    }
};