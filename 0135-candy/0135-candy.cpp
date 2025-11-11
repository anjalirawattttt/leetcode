class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candies(n,1);
        int i=1;
        while(i<n){
            if(ratings[i]>ratings[i-1])candies[i]=candies[i-1]+1;
            i++;
        }
        i=n-2;
        while(i>=0){
            if(ratings[i]>ratings[i+1])candies[i]=max(candies[i],candies[i+1]+1);
            i--;
        }
        int totalCandies=0;
        for(int i=0;i<n;i++){
            totalCandies+=candies[i];
        }
        return totalCandies;    
    }
};