class Spreadsheet {
    vector<vector<int>> ss;
    int r;
public:
    Spreadsheet(int rows) {
        ss.resize(rows,vector<int>(26,0)); 
        r=rows;   
    }
    
    void setCell(string cell, int value) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1)); 
        ss[row-1][col] = value;
    }
    
    void resetCell(string cell) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1)); 
        ss[row-1][col] = 0;       
    }

    int help(string temp){
        if( all_of(temp.begin(),temp.end(),::isdigit) )return stoi(temp);
        int col=temp[0]-'A';
        int row=stoi(temp.substr(1)); 
        if(col<0 || col>=26 || row-1<0 || row-1>=r)return 0;
        return ss[row-1][col];

    }
    
    int getValue(string formula) {
        int i=0;
        string temp="";
        if(formula[i]=='=')i++;
        while(formula[i]!='+'){
            temp+=formula[i];
            i++;
        }
        if(formula[i]=='+')i++;
        int first=help(temp);
        temp="";
        while(i<formula.length()){
            temp+=formula[i];
            i++;
        }
        int second=help(temp);
        return first+second;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */