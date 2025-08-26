class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();

        //pick first k cards
        int lS=0,rS=0;
        int maxS=0;
        for(int i=0;i<k;i++)lS+=cardPoints[i];
        maxS=lS;

        int l=k-1,r=n-1;
        while(l>=0){
            lS-=cardPoints[l];
            l--;
            rS+=cardPoints[r];
            r--;
            maxS=max(maxS,lS+rS);
        }

        return maxS;

        
        
    }
};