class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m != n) return false;
        
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        for (int i = 0; i < m; i ++) {
            char schar = s[i];
            char tchar = t[i];
            
            if(m1.find(schar) != m1.end() && m1[schar] != tchar) return false;
            if(m2.find(tchar) != m2.end() && m2[tchar] != schar) return false;
            
            m1[schar] = tchar;
            m2[tchar] = schar;
        }
        return true;
    }
};