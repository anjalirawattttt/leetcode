class Solution {
    const int MOD=1e7;
public:
    int generateHashcode(string &s){
        long long hashcode=0;
        for(int i=0;i<s.length();i++){
            int contri=( hashcode*26+s[i] )%MOD;
            hashcode+= contri ;
        }
        return (int)hashcode;
    }

    int rabin_karp(string a,string b){
        int n=a.length();
        int m=b.length();
        int hash=generateHashcode(b);
        for(int i=0;i<=n-m;i++){
            string temp=a.substr(i,m);
            int match=generateHashcode(temp);
            if(hash==match){
                if(temp==b)return 1;
            }
        }
        return -1;
    } 

    int repeatedStringMatch(string a, string b) {
        if(b.empty())return 0;
        if(a==b)return 1;
        int count=1;
        string source=a;
        while(source.length()<b.length()){
            count++;
            source+=a;
        }
        if(a==b)return count;
        if(rabin_karp(source,b)!=-1)return count;
        if(rabin_karp(source+a,b)!=-1)return count+1;
        return -1;
    }
};