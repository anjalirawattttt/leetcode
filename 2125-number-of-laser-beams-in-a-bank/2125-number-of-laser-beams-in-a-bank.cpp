class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size();
        int n=bank[0].size();
        int ans=0;
        int prevLasers=-1;
        for(int i=0;i<m;i++){
            int lasers=0;
            for(int j=0;j<n;j++){
                if(bank[i][j]=='1')lasers++;
            }
            if(prevLasers!=-1){
                ans+=prevLasers*lasers;
            }
            if(lasers>0)prevLasers=lasers;
        }  
        return ans;  
    }
};