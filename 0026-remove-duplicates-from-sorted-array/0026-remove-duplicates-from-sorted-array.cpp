class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        int ptr = 0;
        while( ptr < n ){
            nums[idx++]=nums[ptr];
            while(ptr<n-1 && nums[ptr]==nums[ptr+1])ptr++;
            ptr++;
        } 
        return idx;
    }
};