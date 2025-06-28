class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        vector<int> res;
        int n=nums.size();

        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end());

        sort(v.begin()+n-k,v.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second < b.second;
        });

        for(int i=n-k;i<n;i++){
            res.push_back(v[i].first);
        }
        return res;    
    }
};