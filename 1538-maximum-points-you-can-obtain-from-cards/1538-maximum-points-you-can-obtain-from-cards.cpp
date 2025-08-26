class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        //pick first k cards
        int l=0,r=n-1;
        int maxS=0,score=0;
        while(l<k){
            score+=cardPoints[l];
            l++;
        }   
        l--;
        maxS=score;

        while(l>=0){
            score-=cardPoints[l];
            l--;
            score+=cardPoints[r];
            r--;
            maxS=max(maxS,score);
        }

        return maxS;

        
        
    }
};