class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int sum=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> m;        
            for(int j=i;j<n;j++){
                m[s[j]]++;
                int minf=n,maxf=0;
                for(auto &p:m){
                    minf=min(minf,p.second);
                    maxf=max(maxf,p.second);
                }
                sum+=maxf-minf;
            }
        }
        return sum;    
    }
};