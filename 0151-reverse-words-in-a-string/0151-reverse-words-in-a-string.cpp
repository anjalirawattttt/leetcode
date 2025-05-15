class Solution {
public:
    void reverse(string &s){
        int l=0;
        int r=s.length()-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }

    string reverseWords(string s) {
        int n=s.length();
        string ans;
        string word="";
        


        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                while(i>0 && s[i-1]==' '){
                    i--;
                }
                if(!word.empty()){
                    reverse(word);
                    ans+=word;
                    ans+=' ';
                    word="";
                }                
            }
            else{
                word+=s[i];
            }
        }
        if(!word.empty()){
                    reverse(word);
                    ans+=word;
                    ans+=' ';
                    word="";
        }
        ans.erase(ans.length()-1,1);

        
        return ans;
    }
};