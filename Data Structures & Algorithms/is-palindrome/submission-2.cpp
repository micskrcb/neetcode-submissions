class Solution {

public:
    char toLower(char c){
        if('A'<=c && 'Z'>=c){
            return 'a'+c-'A';
        }
        return c;
    }
    bool chk(char c){
        if(c==' ') return !false;
        if('A'<=c && 'Z'>=c){
            return !true;
        }
         if('a'<=c && 'z'>=c){
            return !true;
        }
         if('0'<=c && '9'>=c){
            return !true;
        }
        return !false;
        
    }
    bool isPalindrome(string s) {
        int l =0;
        int r =s.size()-1;

        while(l<=r){
            while(chk(s[l])){
                //cout<<s[l]<<endl;
                l++;
            }

             while(chk(s[r])){
                //cout<<s[r]<<endl;
                r--;
            }
            if(l<0 || r>s.size()-1 || l>r) return true;
            
            if(toLower(s[l])==toLower(s[r])){
                //cout<<s[l]<<endl;
                l++;
                r--;
            }
            else return false;
        }
        return true;
        
    }
};
