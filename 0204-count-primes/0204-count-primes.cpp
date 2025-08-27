class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        vector<bool> isPrime(n,true);   
        for(int i=2;i<sqrt(n);i++){
            for(int j=2;i*j<n;j++){
                isPrime[i*j]=false;
            }   
        }
        for(int i=2;i<isPrime.size();i++){
            if(isPrime[i])ans++;
        }
        return ans;
    }
};