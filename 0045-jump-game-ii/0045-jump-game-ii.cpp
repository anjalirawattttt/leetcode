class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int n=nums.size();
        int end=0,farthest=0;
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,i+nums[i]);
            if(i==end){
                jumps++;
                end=farthest;
                // if(end>=n-1)break;
            }
        }
        return jumps;    
    }
};