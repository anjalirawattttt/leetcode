class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string> v(numRows);
        int i=0,j=-1;
        bool inc=true;
        while(i<s.length()){
            if(j==-1){
                v[0]+=s[i];
                j=0;
            }
            else{                
                v[j]+=s[i];
                if(j==numRows-1 || j==0)inc=!inc;
            }
            if(inc)j++;
            else j--;
            i++;
        }
        string temp="";
        for(int i=0;i<v.size();i++){
            temp+=v[i];
        }
        return temp;
    }
};