class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int letters=t.length();
        if(letters>n)return "";
        int st=-1;  
        int minLen=INT_MAX;
        unordered_map<char,int> m;
        //count frequencies
        for(char &ch:t){
            m[ch]++;
        } 
        //find window
        int l=0,r=0;
        while(r<n){
            if(m.find(s[r])!=m.end()){
                if(m[s[r]]>0){
                    letters--; 
                }  
                m[s[r]]--; 
            }
            while(l<n && letters==0){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    st=l;
                }
                if(m.find(s[l])!=m.end()){
                    m[s[l]]++;
                    if(m[s[l]]>0){
                        letters++;
                    }
                }
                l++;
            }
            r++;
        }
        if(minLen==INT_MAX)return "";
        return s.substr(st,minLen);
    }
};