class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int r=0;
        int n=nums.size();
        while(r<n){
            if(m.find(nums[r])==m.end())m[nums[r]]=r;
            else{
                if(r-m[nums[r]]<=k)return true;
                else m[nums[r]]=r;
            }
            r++;
        }  
        return false;  
    }
};