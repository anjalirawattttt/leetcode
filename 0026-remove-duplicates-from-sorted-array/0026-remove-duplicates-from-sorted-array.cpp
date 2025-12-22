class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=1;
        int prev=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=prev){
                prev=nums[i];
                swap(nums[i],nums[idx]);
                idx++;
            }
        }
        return idx;
    }
};