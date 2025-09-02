class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx=0,i=0,n=nums.size();
        while(i<n){
            while(i<n && nums[i]==0){
                i++;
            }
            if(i<n){
                swap(nums[i],nums[idx++]);
            }
            i++;
        }    
    }
};