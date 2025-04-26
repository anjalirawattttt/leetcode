class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        vector<int> ans;
        for(int i=0;i<n;i++){
            v[i].first=nums[i];
            v[i].second=i;
        }
        sort(v.begin(),v.end());
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            if(v[l].first+v[r].first == target){
                ans.push_back(v[l].second);
                ans.push_back(v[r].second);
                break;
            }
            else if(v[l].first+v[r].first < target){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};