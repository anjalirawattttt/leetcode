class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> result;
        unordered_map<int,int> freq;
        for(int num:nums)freq[num]++;

        vector<vector<int>> bucket(n+1);
        for(auto &p:freq){
            bucket[p.second].push_back(p.first);
        }

        for(int i=n;i>0;i--){
            for(int &ele:bucket[i]){
                result.push_back(ele);
                if(result.size()==k)return result;
            }
        }
        return result;    
    }
};