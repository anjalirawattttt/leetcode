class Solution {
public:
    int dayOfYear(string date) {
        unordered_map<int,int> m={
            {-1,0},
            {1,31},
            {2,59},
            {3,90},
            {4,120},
            {5,151},
            {6,181},
            {7,212},
            {8,243},
            {9,273},
            {10,304},
            {11,334},
            {12,365}
        };   
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,7));
        int day=stoi(date.substr(8,10));

        int days=0;
        
        days+=m[month-1];
        days+=day;

        if( (year%4==0 && year%100!=0) || year%400==0){
            if(month>2)days+=1;
        }



        return days;
        


    }
};