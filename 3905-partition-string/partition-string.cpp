class Solution {
public:
    vector<string> partitionString(string s) {
        int n=s.size();
        set<string>st;
         vector<string>ans;
        string ss;
        for(int i=0;i<n;i++){         
            ss+=s[i];
            if(st.find(ss)==st.end()){
           st.insert(ss);
           ans.push_back(ss);
           ss="";
            }
            else continue;
        }
       
        return ans;
    }
};