class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int ans;
        int diff = INT_MAX;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i<n-2 ; i++){
            if(i > 0 && nums[i]==nums[i-1])continue;
            int l = i+1 , r = n-1;
            while( l < r ){
                int sum = nums[i] + nums[l] + nums[r];
                if( sum == target ){
                    return target;
                }
                else if( sum < target ){
                    if(abs(sum-target) < diff){
                        diff = abs(sum-target);
                        ans = sum;
                    }
                    l++;
                }
                else {
                    if(abs(sum-target) < diff){
                        diff = abs(sum-target);
                        ans = sum;
                    }
                    r--;
                }
            }
        }
        return ans;      
    }
};