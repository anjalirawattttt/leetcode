class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>> ans;  
        //sum , i ,j
        priority_queue< pair<long long,pair<int,int>> ,vector<pair<long long,pair<int,int>>> ,greater<pair<long long,pair<int,int>>> > pq;
        set<pair<int,int>> s;

        pq.push({(long long)nums1[0]+nums2[0],{0,0}});
        s.insert({0,0});
        while(k>0 && !pq.empty()){
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            // long long sum=pq.top().first;
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            k--;
            if(i<n1 && j+1<n2){
                if(s.find({i,j+1})==s.end()){
                    s.insert({i,j+1});
                    pq.push({(long long)nums1[i]+nums2[j+1],{i,j+1}});
                }
            }
            if(i+1<n1 && j<n2){
                if(s.find({i+1,j})==s.end()){
                    s.insert({i+1,j});
                    pq.push({(long long)nums1[i+1]+nums2[j],{i+1,j}});
                }
            }
        }   
        return ans;
    }
};