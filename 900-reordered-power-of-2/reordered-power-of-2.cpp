class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // Convert n to sorted string
        string s = to_string(n);
        sort(s.begin(), s.end());

        // Check all powers of 2 up to 10^9
        for (int i = 0; i < 31; i++) {  // 2^30 = 1073741824 > 10^9
            int pow2 = 1 << i;
            string t = to_string(pow2);
            sort(t.begin(), t.end());
            if (s == t) return true;
        }
        return false;
    }
};
