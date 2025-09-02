class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=1,ele=nums[0];
        int i=1,n=nums.size();
        while(i<n){
            while(i<n && nums[i]==ele){
                i++;
            }
            if(i<n){
                ele=nums[i];
                swap(nums[i],nums[idx]);
                idx++;
            }
            i++;
        } 
        return idx;  
    }
};