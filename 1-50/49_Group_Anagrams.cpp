class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
            return vector<vector<string> >();

        int len = strs.size();
        sort(strs.begin(), strs.end());

        vector<vector<string> > result;
        map<string, vector<string>> strMap;

        for (int i = 0; i < len; i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());

            strMap[str].push_back(strs[i]);
        }

        for (map<string, vector<string> >::iterator iter = strMap.begin(); iter != strMap.end(); iter++)
            result.push_back(iter->second);

        return result;
    }
};