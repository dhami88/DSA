class Solution {
public:
    int strStr(string haystack, string needle) {
        int index=haystack.find(needle);
        if(haystack.find(needle)!=string::npos){
            return index;
        }
        return -1;
    }
};