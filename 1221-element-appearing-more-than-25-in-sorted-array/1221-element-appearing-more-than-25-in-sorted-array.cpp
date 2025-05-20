class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> m;
        for(int &a:arr){
            m[a]++;
        }
        for(auto &p:m){
            if(p.second > n/4)return p.first;
        }
        return -1;
    }
};