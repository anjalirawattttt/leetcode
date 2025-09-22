class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int& num:nums){
            m[num]++;
        }
        int count=0;
        int maxFreq=0;
        for(auto &p:m){
            if(p.second>maxFreq){
                maxFreq=p.second;
                count=maxFreq;
            }
            else if(p.second==maxFreq){
                count+=maxFreq;
            }
        }
        return count;
    }
};