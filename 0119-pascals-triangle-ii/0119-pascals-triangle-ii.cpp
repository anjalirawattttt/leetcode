class Solution {
public:
    long long fact(int n){
        if(n==0 || n==1)return 1;
        return n*fact(n-1);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        long long val = 1;
        for (int k = 1; k < rowIndex; k++) {
            val = val * (rowIndex - k + 1) / k;
            row[k] = val;
        }
        return row;   
    }
};