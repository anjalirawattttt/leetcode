class TaskManager {
    struct cmp{
        bool operator()(const pair<int,int>& a,const pair<int,int>& b)const{
            if(a.first==b.first)return a.second<b.second;
            return a.first<b.first;
        }
    };
    //taskid->userid
    unordered_map<int,int> tu;
    //taskid->priority
    unordered_map<int,int> tp;
    //userid->priority,tasks
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pt;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            tu[tasks[i][1]]=tasks[i][0];
            tp[tasks[i][1]]=tasks[i][2];
            pt.push({tasks[i][2],tasks[i][1]});
        }    
    }
    
    void add(int userId, int taskId, int priority) {
        tu[taskId]=userId;
        tp[taskId]=priority;
        pt.push({priority,taskId});    
    }
    
    void edit(int taskId, int newPriority) {
        tp[taskId]=newPriority;
        pt.push({newPriority,taskId});

    }
    
    void rmv(int taskId) {
        tu.erase(taskId);
        tp.erase(taskId);
    }
    
    int execTop() {
        int userid=-1;
        int anstaskid=-1;
        while(!pt.empty() && (tp.find(pt.top().second)==tp.end() || tp[pt.top().second]!=pt.top().first)) pt.pop();
        if(!pt.empty()){
            anstaskid=pt.top().second;
        }
        if(anstaskid==-1)return -1;
        userid=tu[anstaskid];
        tp.erase(anstaskid);
        tu.erase(anstaskid);
        return userid; 
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */