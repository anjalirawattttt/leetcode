class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return 0;
        int jumps=0,maxRechable=0,prevMaxRechable=0;

        for(int i=0;i<n-1;i++){
            maxRechable=max(maxRechable,i+nums[i]);
            if(i==prevMaxRechable){
                jumps++;
                prevMaxRechable=maxRechable;
            }
        }
        return jumps;
        

    }
};