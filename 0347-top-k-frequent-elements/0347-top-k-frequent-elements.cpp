class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        //count frequencies
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        for(auto &p:m){
            pq.push({p.second,p.first});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};