class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i<n-2 ; i++){
            if(i > 0 && nums[i]==nums[i-1])continue;
            int l = i+1 , r = n-1;
            while( l < r ){
                if( nums[i] + nums[l] + nums[r] == 0 ){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l<n-1 && nums[l+1]==nums[l])l++;
                    l++;
                }
                else if( nums[i] + nums[l] + nums[r] < 0 ){
                    l++;
                }
                else {
                    r--;
                }
            }

        }
        return ans;    
    }
};