class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (const string& str : strs) {
            string strS = str;
            sort(strS.begin(), strS.end());
            map[strS].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& a : map) res.push_back(a.second);

        return res;
    }
};
