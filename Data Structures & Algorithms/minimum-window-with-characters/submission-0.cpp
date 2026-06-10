class Solution {
   public:
    bool chk(vector<int> mp) {
        for (auto a : mp) {
           // cout << a;
            if (a > 0) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int ansl = -1;
        int ansr = -1;

        int l = 0;
        int r = 0;
        // vector<int> mp(256,0);
        vector<int> m(256, 0);
        for (auto a : t) {
            m[a]++;
        }

        while (r < s.size()) {
            //cout << l << r << endl;
            char curr = s[r];
            m[curr]--;
            while (chk(m)) {
                //cout << "hi" << endl;
                if (ansl != -1) {
                    if (ansr - ansl > r - l) {
                        ansr = r;
                        ansl = l;
                    }
                } else {
                    ansl = l;
                    ansr = r;
                }

                m[s[l]]++;
                l++;
            }
            r++;
        }
        string ans = "";
        if (ansl == -1) {
            return ans;
        }
        cout << ansl << ansr << endl;
        for (int i = ansl; i <= ansr; i++) {
            ans += s[i];
        }
        return ans;
    }
};
