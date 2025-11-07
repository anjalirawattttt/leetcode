class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int idx=1;
        int prev=nums[0];
        int k=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=prev){
                prev=nums[i];
                swap(nums[i],nums[idx++]);
                k++;
            }
        }  
        return k;  
    }
};