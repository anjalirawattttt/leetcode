class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int> m;
        for(string &word:words){
            m[word]++;
        }

        int wordLen=words[0].length();
        int totalLen=wordLen * words.size();
        int n=s.length();

        for(int i=0;i<=n-totalLen;i++){
            int l=i,r=i+totalLen; 
            int count=0;
            unordered_map<string,int> seen; 
            while(l<r){
                string temp=s.substr(l,wordLen);
                if(m.find(temp)==m.end()){
                    break;
                }
                else{
                    seen[temp]++;
                    count++;
                }
                l+=wordLen;
            }  
            if(count==words.size()){
                for(auto &p:m){
                    if(m[p.first]!=seen[p.first]){
                        count=-1;
                        break;
                    }
                }
                if(count!=-1)ans.push_back(i);
            }

        }

        return ans;
    }
};