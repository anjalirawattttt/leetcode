class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {       int n=nums.size();
        vector<int> diff(n+1,0);

        for(auto &q:queries){
            diff[q[0]]++;
            if(q[1]+1<n)diff[q[1]+1]--;
        }

        int apply=0;
        for(int i=0;i<n;i++){
            apply+=diff[i];
            if(nums[i]>apply)return false;
        }
        return true;


        
    }
};