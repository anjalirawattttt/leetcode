class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxPoints=0,points=0;
        int n=cardPoints.size();

        for(int i=0;i<k;i++){
            points+=cardPoints[i];
        }  
        maxPoints=max(maxPoints,points);

        int l=k-1,r=n-1;
        while(l>=0){
            points-=cardPoints[l];
            points+=cardPoints[r];
            maxPoints=max(maxPoints,points);
            l--;
            r--;
        }  

        return maxPoints;

    }
};