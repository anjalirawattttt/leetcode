class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.empty() || s.empty())return ans;

        unordered_map<string,int> m;
        for(string &word:words){
            m[word]++;
        }

        int wordLen=words[0].length();
        int totalLen=wordLen * words.size();
        int n=s.length();
        if(n<totalLen)return ans;

        for(int i=0;i<wordLen;i++){
            int left=i,count=0;
            unordered_map<string,int> seen;
            for(int j=i;j+wordLen<=n;j+=wordLen){
                string temp=s.substr(j,wordLen);
                if(m.find(temp)!=m.end()){
                    seen[temp]++;
                    count++;
                    while(seen[temp]>m[temp]){
                        string leftWord=s.substr(left,wordLen);
                        seen[leftWord]--;
                        count--;
                        left+=wordLen;
                    }
                    if(count==words.size())ans.push_back(left);
                }
                else{
                    count=0;
                    seen.clear();
                    left=j+wordLen;
                }
            }

        }

        return ans;
    }
};