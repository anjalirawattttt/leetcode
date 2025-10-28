class Solution {
    const int MOD=1e7;
public:

    int rabin_karp(string a,string b){
        int n=a.length();
        int m=b.length();

        long long hashcode=0;
        long long curr=0;
        long long power=1;

        for(int i=0;i<m;i++){
            if(i<m-1){
                power=(power*26)%MOD;
            }
            hashcode=( (hashcode*26) + (b[i]-'a') )%MOD;
            curr=( (curr*26) + (a[i]-'a') )%MOD;            
        }

        if(curr==hashcode){
            string temp=a.substr(0,m);
            if(temp==b)return 1;
        }

        
        for(int i=m;i<n;i++){
            curr=( (curr-((a[i-m]-'a')*power)%MOD)*26 +(a[i]-'a') )%MOD;
            if(curr<0)curr+=MOD;
            if(curr==hashcode){
                string temp=a.substr(i-m+1,m);
                if(temp==b)return 1;
            }
        }


        return -1;
    } 

    int repeatedStringMatch(string a, string b) {
        if(b.empty())return 0;
        if(a.empty())return -1;
        if(a==b)return 1;

        int count=1;
        string source=a;
        while(source.length()<b.length()){
            count++;
            source+=a;
        }

        if(source==b)return count;
        if(rabin_karp(source,b)!=-1)return count;
        if(rabin_karp(source+a,b)!=-1)return count+1;
        return -1;
    }
};