class Solution {
public:
    string frequencySort(string s) {
        //hash table 
        //stores frequency
        unordered_map<char,int> hash;
        for(int i=0;i<s.length();i++){
            hash[s[i]]++;
        }   

        //maxheap
        priority_queue<pair<int,char>> pq;
        for(auto &p:hash){
            pq.push({p.second,p.first});
        }

        string ans="";
        while(!pq.empty()){
            //size,char
            ans.append(pq.top().first,pq.top().second);
            pq.pop();
        }

        return ans;
    }
};