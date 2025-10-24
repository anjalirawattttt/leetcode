class Solution {
public:
    const int MOD=1337;
    long long help(long long a,long long b){
        if(b==0)return 1;
        if(b==1)return a;
        if(a==0 || a==1)return a;
        long long ans=1;
        while(b>0){
            if(b%2){
                ans=(ans*a)%MOD;    
            }
            a=(a*a)%MOD;
            b=b>>1;
        }
        return ans%MOD;
    }
    int superPow(int a, vector<int>& b) {
        if(a==0 || a==1)return a;
        a=a%MOD;
        long long ans=1;
        for(int i=0;i<b.size();i++){
            ans=help(ans,10);
            ans=(ans*help(a,b[i]))%MOD;         
        }  
        return ans%MOD; 
    }
};