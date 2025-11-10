class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str1=strs[0];
        int n=strs.size();

        for(int i=1;i<n;i++){
            string str2=strs[i];
            int j=0;
            while(j<str1.length() && j<str2.length()){
                if(str1[j]==str2[j]){
                    j++;
                }
                else break;
            }
            str1=str1.substr(0,j);
        }  
        return str1;  
    }
};