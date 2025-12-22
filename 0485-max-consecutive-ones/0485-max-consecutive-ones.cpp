class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes=0;
        int ones=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ones++;
            }
            else{
                maxOnes=max(maxOnes,ones);
                ones=0;
            }
        }
        maxOnes=max(maxOnes,ones);
        return maxOnes;    
    }
};