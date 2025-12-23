class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<=n-4;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<=n-3;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int k=j+1,l=n-1;
                while(k<l){
                    if((long long)nums[i]+nums[j]+nums[k]+nums[l]==target){
                        // cout<<i<<j<<k<<l;
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k<n-1 && nums[k]==nums[k+1]){
                            // cout<<nums[k]<<" "<<nums[k+1]<<endl;
                            k++;
                        }
                        k++;
                        l=n-1;
                    }
                    else if((long long)nums[i]+nums[j]+nums[k]+nums[l]<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;        
    }
};