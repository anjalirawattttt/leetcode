class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        //minheap
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        //count frequencies
        unordered_map<int,int> m;
        for(int& num:nums){
            m[num]++;
        }
        //put frequencies in minheap
        for(auto &p:m){
            pq.push({p.second,p.first});
            if(pq.size()>k)pq.pop();
        }
        //put the k most frequent in ans
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;    
    }
};