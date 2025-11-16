class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int minEle=nums[0];
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            minEle=min(minEle,nums[i]);
        }
        return sum-(minEle*n);
    }
};