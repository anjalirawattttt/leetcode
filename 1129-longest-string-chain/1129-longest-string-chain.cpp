class Solution {
public:
    bool comp(string &s1,string &s2){
        int n1=s1.length();
        int n2=s2.length();
        if(n1!=n2+1)return false;
        int i=0,j=0;
        while(i<n1){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==n1 && j==n2)return true;
        return false;

    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        int n=words.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if( comp(words[i],words[j])  && 1+dp[j]>dp[i] ){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }  
        return maxi;  
    }
};