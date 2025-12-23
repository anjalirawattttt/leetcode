class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<=n-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==-nums[i]){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<n-1 && nums[j]==nums[j+1])j++;
                    j++;
                    k=n-1;
                }
                else if(nums[j]+nums[k]<-nums[i]){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        
        return ans;    
    }
};