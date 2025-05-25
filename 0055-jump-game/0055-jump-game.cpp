class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        int maxIndex=0;

        for(int i=0;i<n;i++){
            maxIndex=max(maxIndex,i+nums[i]);
            if(nums[i]==0){
                if(maxIndex>i){
                    continue;  
                }
                else{
                    return false;
                }                  
            }
            if(nums[i]>=n-i-1){
                return true;
            }
        } 

        return false;   
    }
};