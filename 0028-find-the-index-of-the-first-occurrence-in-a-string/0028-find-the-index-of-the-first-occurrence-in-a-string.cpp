class Solution {
public:
    int strStr(string haystack, string needle) {
        int index=-1;
        for(int i=0;i<haystack.length();i++){
            int k=i;
            int j=0;
            if(haystack[k]==needle[j]){
                while(k<haystack.length() && j<needle.length() && haystack[k]==needle[j]){
                    k++;
                    j++;
                }
                if(j == needle.length()){
                    index=i;
                    break;
                }
            }
        }
        return index;
    }
};