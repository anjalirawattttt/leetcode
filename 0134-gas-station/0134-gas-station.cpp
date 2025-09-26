class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int given=0,used=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            given+=gas[i];
            used+=cost[i];
        }
        if(used>given)return -1;
        
        
        int tank=0;
        int ans=0;
        for(int i=0;i<n;i++){
            tank+=gas[i]-cost[i];
            if(tank<0){
                tank=0;
                ans=(i+1)%n;
            }
        }
        return ans;

    }
};