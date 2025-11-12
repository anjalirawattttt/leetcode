class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //count frequencies
        unordered_map<int,int> m;
        for(int i=0;i<hand.size();i++){
            m[hand[i]]++;
        }   
        //minHeap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto &p:m){
            pq.push({p.first,p.second});
        }

        while(!pq.empty()){
            vector<pair<int,int>> v;
            int temp=pq.top().first-1;
            for(int i=0;i<groupSize;i++){
                if(pq.empty())return false;
                int num=pq.top().first;
                int freq=pq.top().second;
                pq.pop();
                if(temp!=num-1)return false;
                freq--;
                temp=num;
                v.push_back({num,freq});
            }
            for(int i=0;i<v.size();i++){
                if(v[i].second>0)pq.push(v[i]);
            }

        }
        return true;
    }
};