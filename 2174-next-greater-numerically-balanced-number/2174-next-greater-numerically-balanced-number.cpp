class Solution {
public:
    bool isSafe(int n){
        int num=n;
        unordered_map<int,int> m;
        while(num>0){
            int digit=num%10;
            m[digit]++;
            num/=10;
        }
        for(auto &p:m){
            if(p.first!=p.second)return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        if(n>=666666)return 1224444;
        for(int i=n+1;i<=1224444;i++){
            if(isSafe(i))return i;
        }
        return -1;
    }
};