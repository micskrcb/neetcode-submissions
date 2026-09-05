class TimeMap {
public:
    map<string,map<int,string>> structure;
    map<string,vector<int>> times;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        structure[key][timestamp]=value;
        times[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(times[key].size()==0)return "";
        auto it = upper_bound(times[key].begin(),times[key].end(),timestamp);
        if(it == times[key].begin())return "";
        it--;return structure[key][*it];      
    }
};
