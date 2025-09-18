class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int l=0,r=n-1;
        while(l<r){
            int sum=v[l].first+v[r].first;
            if(sum==target){
                ans[0]=v[l].second;
                ans[1]=v[r].second;
                break;
            }
            else if(sum<target)l++;
            else r--;
        }
        sort(ans.begin(),ans.end());
        return ans;    
    }
};