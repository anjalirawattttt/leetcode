class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int minReach=0,maxReach=0;
        int jumps=0;
        while(maxReach<n-1){
            int maxx=maxReach;
            for(int i=minReach;i<=maxReach;i++){
                maxx=max(maxx,i+nums[i]);
            }
            minReach=maxReach+1;
            maxReach=maxx;
            jumps++;
        }
        return jumps;   
    }
};