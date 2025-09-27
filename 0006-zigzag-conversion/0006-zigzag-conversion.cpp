class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<vector<char>> v(numRows);
        int i=0,j=-1;
        bool inc=true;
        while(i<s.length()){
            if(j==-1){
                v[0].push_back(s[i]);
                j=0;
            }
            else{                
                v[j].push_back(s[i]);
                if(j==numRows-1 || j==0)inc=!inc;
            }
            if(inc)j++;
            else j--;
            i++;
        }
        string temp="";
        for(int i=0;i<v.size();i++){
            for(j=0;j<v[i].size();j++){
                temp+=v[i][j];
            }
        }
        return temp;
    }
};