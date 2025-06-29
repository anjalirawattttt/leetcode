class Solution {
public:
    

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> maxFreq(26,0);
        for(const string &word:words2){
            vector<int> freq(26,0);
            for( const char &ch:word){
                freq[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                maxFreq[i]=max(maxFreq[i],freq[i]);
            }
        } 

        for(const string &word:words1){
            bool flag=true;
            vector<int> freq(26,0);
            for( const char &ch:word){
                freq[ch-'a']++;
            }

            for(int i=0;i<26;i++){
                if(freq[i]<maxFreq[i]){
                    flag=false;
                    break;
                }
            }
            if(flag)res.push_back(word);
        }  

        return res;

    }
};