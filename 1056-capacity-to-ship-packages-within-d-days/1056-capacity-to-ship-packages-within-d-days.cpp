class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int result=INT_MAX;
        int sum=0,maxx=weights[0];
        for(int &weight:weights){
            sum+=weight;
            maxx=max(maxx,weight);
        }
        
        

        int cal,summ;
        int l=maxx,r=sum,mid;
        while(l<=r){
            summ=0;
            cal=1;
            mid = l + (r-l)/2;
            for(int &weight:weights){
                summ+=weight;
                if(summ>mid){
                    cal++;
                    summ=weight;
                }
            }
            if(cal<=days){
                result=min(result,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};