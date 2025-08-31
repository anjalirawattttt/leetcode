class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //count frquencies
        unordered_map<char,int> m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        } 

        //maxheap
        priority_queue<int> pq;
        for(auto &p:m){
            pq.push(p.second);
        } 

        int ans=0;
        while(!pq.empty()){
            vector<int> v;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    v.push_back(freq-1);
                }
            }
            for(int i=0;i<v.size();i++){
                if(v[i]>0)pq.push(v[i]);
            }
            if(pq.empty()){
                ans+=v.size();
            }
            else{
                ans+=n+1;
            }

        }
        return ans;          
    }
};