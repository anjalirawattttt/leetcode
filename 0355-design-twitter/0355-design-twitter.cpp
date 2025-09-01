class Twitter {
    int timeStamp;
    unordered_map<int,unordered_set<int>> followed;
    unordered_map<int,vector<pair<int,int>>> tweets;
public:
    Twitter() {
        timeStamp=0;    
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp,tweetId});
        timeStamp++;   
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        //minheap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto &p:tweets[userId]){
            pq.push(p);
            if(pq.size()>10)pq.pop();
        }

        for(auto &user:followed[userId]){
            for(auto &p:tweets[user]){
                pq.push(p);
                if(pq.size()>10)pq.pop();
            }  
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        followed[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followed[followerId].erase(followeeId);    
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */