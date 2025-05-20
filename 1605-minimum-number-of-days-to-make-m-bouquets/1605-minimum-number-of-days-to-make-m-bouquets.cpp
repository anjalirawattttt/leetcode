class Solution {
public:
    int getDays(int lower,int upper,vector<int>& bloomDay,int m,int k){
        int l=lower,r=upper,result=upper;
        while(l<=r){
            int cap=l+(r-l)/2;
            int calB=0;
            int count=0;

            for(int b:bloomDay){
                if(b<=cap){
                    count++;
                    if(count==k){
                    calB++;
                    count=0;
                }
                }
                else{
                    count=0;
                }
            }

            if(calB>=m){
                r=cap-1;
            }
            else{
                l=cap+1;
            }
        }
        return l;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(1LL*m*k >n)return -1;
        int lower=1,upper=bloomDay[0];

        for(int &b:bloomDay){
            upper=max(upper,b);
        }

        int days=getDays(lower,upper,bloomDay,m,k);
        return days;
    }
};