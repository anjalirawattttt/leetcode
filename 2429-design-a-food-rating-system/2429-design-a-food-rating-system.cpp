class FoodRatings {
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first == b.first)
                return a.second > b.second;  // lexicographically smaller string first
            return a.first < b.first;        // higher rating first
        }
    };
    unordered_map<string,int> fr;
    unordered_map<string,string> fc;
    unordered_map<string,priority_queue< pair<int,string>,vector<pair<int,string>>,cmp >> comp;
    //cuisine->pq
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            fr[foods[i]]=ratings[i];
            fc[foods[i]]=cuisines[i];
            comp[cuisines[i]].push({ratings[i],foods[i]});
        }

    }
    
    void changeRating(string food, int newRating) {
        fr[food]=newRating;
        string cuisine=fc[food];
        comp[cuisine].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        while(!comp[cuisine].empty()){
            auto [rating,food]=comp[cuisine].top();
            if(rating==fr[food])return food;
            comp[cuisine].pop();
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */