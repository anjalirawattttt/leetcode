class Solution {
public:
    void help(int num,int d,string &temp){
        if(num==0)return ;
        int digit=num%10;
        num=num/10;   
        help(num,d+1,temp); 
        if(d==4){
            for(int i=0;i<digit;i++)temp+="M";
        }
        else if(d==3){
            if(digit==4){
                temp+="CD";
            }
            else if(digit==9){
                temp+="CM";
            }
            else if(digit>=5){
                temp+="D";
                digit=digit-5;
                for(int i=0;i<digit;i++)temp+="C";
            }
            else if(digit<5){
                for(int i=0;i<digit;i++)temp+="C";
            }
        }
        else if(d==2){
            if(digit==4){
                temp+="XL";
            }
            else if(digit==9){
                temp+="XC";
            }
            else if(digit>=5){
                temp+="L";
                digit=digit-5;
                for(int i=0;i<digit;i++)temp+="X";
            }
            else if(digit<5){
                for(int i=0;i<digit;i++)temp+="X";
            }
        }
        else if(d==1){
            if(digit==4){
                temp+="IV";
            }
            else if(digit==9){
                temp+="IX";
            }
            else if(digit>=5){
                temp+="V";
                digit=digit-5;
                for(int i=0;i<digit;i++)temp+="I";
            }
            else if(digit<5){
                for(int i=0;i<digit;i++)temp+="I";
            }
        }




    }
    string intToRoman(int num) {
        string ans="";
        // unordered_map<int,string> m={
        //     {1,"I"},
        //     {5,"V"},
        //     {10,"X"},
        //     {50,"L"},
        //     {100,"C"},
        //     {500,"D"},
        //     {1000,"M"}
        // };
        // int n=num;
        // int d=0;
        // while(n>0){
        //     d++;
        //     n=n/10;
        // }
        help(num,1,ans);    
        return ans;
    }
};