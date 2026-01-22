class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m=land.size();
        int n=land[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1 ){
                    int tempi=i;
                    int tempj=j;
                    while(tempi<m-1 && land[tempi+1][j]==1){
                        tempi++;
                    }
                    while(tempj<n-1 && land[i][tempj+1]==1){
                        tempj++;
                    }
                    ans.push_back({i,j,tempi,tempj});
                    for(int ai=i;ai<=tempi;ai++){
                        for(int aj=j;aj<=tempj;aj++){
                            land[ai][aj]=0;
                        }
                    }
                }
            }
        } 
        return ans;   
    }
};