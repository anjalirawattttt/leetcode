class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candies(n,1);
        //left to right pass
        int i=1;
        while(i<n){
            if(ratings[i-1]<ratings[i]){
                candies[i]=candies[i-1]+1;
            }
            i++;
        }
        //right to left pass
        i=n-2;
        while(i>=0){
            if(ratings[i]>ratings[i+1]){
                candies[i]=max(candies[i],candies[i+1]+1);
            }
            i--;
        }
        int ans=0;
        for(int j=0;j<n;j++){
            ans+=candies[j];
        }
        return ans;


    }
};