class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> v;
        vector<int> freq(10,0);
        for(int digit:digits)freq[digit]++;

        for(int i=1;i<=9;i++){
            if(freq[i]==0)continue;
            freq[i]--;
            for(int j=0;j<=9;j++){
                if(freq[j]==0)continue;
                freq[j]--;
                for(int k=0;k<=9;k+=2){
                    if(freq[k]==0)continue;
                    int num=100*i + 10*j + k;
                    v.push_back(num);
                }
                freq[j]++;
            }
            freq[i]++;
        }
        
       
        return v;
    }
};