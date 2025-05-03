class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int &num:nums)m[num]++;
        for(auto &p:m){
            if(p.second>1)return true;
        }
        return false;
    }
};