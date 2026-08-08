class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        for (auto& a : nums) myMap[a]++;

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& [nums, count] : myMap) bucket[count].push_back(nums);

        vector<int> res;
        for (int i = nums.size(); i >= 0 && res.size() < k; --i) {
            if (bucket[i].empty()) continue;

            sort(bucket[i].begin(), bucket[i].end(), greater<int>());

            for (auto num : bucket[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
