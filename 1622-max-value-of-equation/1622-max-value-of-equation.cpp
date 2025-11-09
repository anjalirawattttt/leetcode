class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n=points.size();
        int maxValue=INT_MIN;
        //i<j
        //abs(xi-xj)======xj-xi
        //sorted by x strictly increasing
        // the equation becomes
        //maximize (yj+xj)+(yi-xi)
        priority_queue<pair<int,int>> pq; 
        //maxheap     
        for(int i=0;i<n;i++){
            while( ( !pq.empty() ) && ( (points[i][0]-points[pq.top().second][0]) > k ))pq.pop();
            if(!pq.empty()){
                int value=pq.top().first+points[i][0]+points[i][1];
                maxValue=max(maxValue,value);
            }
            pq.push({points[i][1]-points[i][0],i});
        }
        return maxValue;   
    }
};