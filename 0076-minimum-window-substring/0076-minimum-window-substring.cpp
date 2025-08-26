class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.length(),n2=t.length();
        if(n2>n1)return "";

        string ans="";
        int minL=INT_MAX,start=0;
        unordered_map<char,int> m;
        for(char &c:t){
            m[c]++;
        }

        int l=0,r=0;
        int x=0;
        while(r<n1){
            m[s[r]]--;
            if(m[s[r]]>=0)x++;

            while(x==t.length()){
                //valid window
                if(r-l+1<minL){
                    start=l;
                    minL=r-l+1;
                }
                
                
                m[s[l]]++;
                if(m[s[l]]>0) x--;
                l++;
            }
            r++;
        }  
        return minL==INT_MAX?"":s.substr(start,minL);    
    }
};