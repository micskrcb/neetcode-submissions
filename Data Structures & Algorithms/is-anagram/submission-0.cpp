class Solution {
public:
    bool isAnagram(string s, string t) {

    vector<int> vec(26,0);
    for(auto a:s){
        vec[a-'a']++;
    }
     for(auto a:t){
        vec[a-'a']--;
    }
    for(auto a: vec){
        if(a) return false;
    }
    return true;
        
    }
};
