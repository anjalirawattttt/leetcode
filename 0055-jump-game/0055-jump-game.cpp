class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxRechableIdx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>maxRechableIdx)return false;
            maxRechableIdx=max(maxRechableIdx,i+nums[i]);   
        }  
        return true;    
    }
};