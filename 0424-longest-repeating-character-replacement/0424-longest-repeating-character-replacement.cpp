class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        int left=0,right=0;
        int maxFreq=INT_MIN;
        int ans=0;
        while(right<s.length()){
            m[s[right]]++;
            if(m[s[right]]>maxFreq){
                maxFreq=m[s[right]];
            }  
            int windowSize=right-left+1;  
            if(windowSize-maxFreq >k){
                 m[s[left]]--;
                left++;
            }
            else{
                ans=max(ans,windowSize);
            }
            right++;
            
        }
        return ans;
    }
};