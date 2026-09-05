class Solution {
public:

    string encode(vector<string>& strs) {
        string sz="";
        if(strs.size()==0)return sz;
        string data="";
        for(auto s:strs){
            sz+=to_string(s.size());
            sz+=',';
            data+=s;
        }
        sz[sz.size()-1]='|';
        sz+=data;
        //cout<<sz<<endl;
        return sz;  


    }

    vector<string> decode(string s) {
        vector<int> sz;
        vector<string> data(0);
        if(s.size()==0) return data;
        int idx = 0;
        int i = 0;
        for(char c : s){
            cout<<c<<" ";
            
            idx++;
            if(c==','){
                i++;
                continue;
            }
            if(c=='|'){
                break;
            }
            if(i>=sz.size()){
                sz.push_back(0);
            }
            sz[i]*=10;
            sz[i]+=c-'0';
           // cout<<" i: "<<i<<" ";                        
        }
       // cout<<sz.size()<<endl;
        i=idx;
        for(auto a: sz){
            cout<<a<<endl;
            string temp = "";
            for(int j=0;j<a;j++){
                temp+=s[i];
                i++;
            }
            data.push_back(temp);
        }
        return data;


    }
};
