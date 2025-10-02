class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int fullB=numBottles;
        int emptyB=0;
        int drunk=0;
        while(fullB>0 || emptyB>=numExchange){
            if(emptyB>=numExchange){
                emptyB-=numExchange;
                numExchange++;
                fullB++;
            }
            else if(fullB>0){
                drunk+=fullB;
                emptyB+=fullB;
                fullB=0;
            }
        }  
        return drunk;
    }
};