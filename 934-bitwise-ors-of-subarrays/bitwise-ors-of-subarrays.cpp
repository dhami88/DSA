class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result, cur, prev;
        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num);
            for (int x : prev) {
                next.insert(x | num);
            }
            prev = next;
            result.insert(prev.begin(), prev.end());
        }
        return result.size();
    }
};
