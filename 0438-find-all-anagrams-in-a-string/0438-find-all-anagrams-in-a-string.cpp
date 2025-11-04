class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> m;
        int letters=0;
        for(char &c:p){
            m[c]++;
            letters++;
        }

        int n1=s.length(),n2=p.length();
        int l=0,r=0,count=0;
        while(r<n1){
            m[s[r]]--;
            count++;
            if(m[s[r]]<0){
                while(l<r && s[l]!=s[r]){
                    m[s[l]]++;
                    count--;
                    l++;
                }
                m[s[l]]++;
                count--;
                l++;
            }
            if(count==letters){
                ans.push_back(l);
            }
            r++;
        }



        
        
        return ans;    
    }
};