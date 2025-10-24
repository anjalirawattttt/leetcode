class Solution {
public:
    bool isSafe(int n){
        string s=to_string(n);
        vector<int> freq(10,0);
        for(char &ch:s){
            freq[ch-'0']++;
        }
        for(int i=0;i<10;i++){
            if(freq[i]!=0 && freq[i]!=i)return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        if(n>=666666)return 1224444;
        for(int i=n+1;i<=666666;i++){
            if(isSafe(i))return i;
        }
        return -1;
    }
};