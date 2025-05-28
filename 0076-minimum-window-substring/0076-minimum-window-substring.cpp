class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        int l=0,r=0,sIndex=-1,count=0,minLength=INT_MAX;

        unordered_map<char,int> mp;
        for(char &ch : t){
            mp[ch]++;
        }

        while(r<m){
            if(mp[s[r]]>0)count++;
            mp[s[r]]--;
            while(count==n){
                if(r-l+1<minLength){
                    sIndex=l;
                    minLength=r-l+1;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0)count--;
                l++;
            }
            r++;
        }  
        return sIndex==-1?"":s.substr(sIndex,minLength); 
    }
};