class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int h=hBars.size();
        int v=vBars.size();

        int hSide=1;
        int maxHside=1;
        int vSide=1;
        int maxVside=1;

        for(int i=1;i<h;i++){
            if(hBars[i]==hBars[i-1]+1){
                // cout<<"1"<<endl;
                hSide++;
            }
            else{
                // cout<<"2"<<endl;
                hSide=1;
            }
            maxHside=max(maxHside,hSide);
        }  

        for(int i=1;i<v;i++){
            if(vBars[i]==vBars[i-1]+1){
                vSide++;
            }
            else{
                vSide=1;
            }
            maxVside=max(maxVside,vSide);
        }
        cout<<maxHside<<" "<<maxVside<<endl;
        int side=min(maxHside,maxVside)+1;
        return side*side;
    }
};