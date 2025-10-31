class Solution {
public:
    static bool myCmp(const pair<int,int> &a,const pair<int,int> &b){
        return a.second<b.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();

        vector<pair<int,int>> pc;
        for(int i=0;i<n;i++){
            pc.push_back({profits[i],capital[i]});
        }  
        sort(pc.begin(),pc.end(),myCmp); 

        priority_queue<pair<int,int>> pq;
        int i=0;
        while(k>0){
            while(i<n && w>=pc[i].second){
                pq.push(pc[i]);
                i++;
            }
            if(pq.empty())return w;
            w+=pq.top().first;
            pq.pop();
            k--;
        }
        return w;
    }
};