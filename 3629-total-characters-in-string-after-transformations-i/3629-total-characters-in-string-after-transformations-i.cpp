class Solution {
public:
    
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        int total=0;

        vector<long long> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }

        while(t--){
            vector<long long> newFreq(26,0);
            for(int i=0;i<26;i++){
                if(i==25){
                    newFreq[0]=(newFreq[0]+freq[i])%MOD;
                    newFreq[1]=(newFreq[1]+freq[i])%MOD;
                }
                else{
                    newFreq[i+1]=(newFreq[i+1]+freq[i])%MOD;
                }
            }
            // for(auto &p:m){
            //     char ch=p.first;
            //     if( ch == 'z' ) {
            //         nm['a'-'a']=(nm['a'-'a'] + p.second) % MOD;
            //         nm['b'-'a']= (nm['b'-'a'] + p.second) % MOD;
            //     }
            //     else{
            //         nm[ch+1]=(nm[ch+1]+p.second) % MOD;                  
            //     }
            // }
            freq=newFreq;
        }


        for(long long count:freq){
            total=(total+count) % MOD;
        }

        return total;

    }
};