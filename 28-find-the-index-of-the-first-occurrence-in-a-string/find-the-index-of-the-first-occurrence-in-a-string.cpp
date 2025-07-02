class Solution {
public:
    int strStr(string haystack, string needle) {
        int index=haystack.find(needle);
        int n=haystack.size();
        if(haystack.find(needle)<n){
            return index;
        }
        return -1;
    }
};