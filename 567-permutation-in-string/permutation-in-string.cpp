class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        sort(s1.begin(),s1.end());
        //sliding window approach --length of sliding window = n
        map<char,int>m1;
        map<char,int>m2;
        for(int i=0;i<n;i++){
            m1[s1[i]]++;
        }
        int l=0;
        for(int j=0;j<m;j++){
            m2[s2[j]]++;
            if(j>=n){
                m2[s2[l]]--;
                if (m2[s2[l]] == 0) m2.erase(s2[l]);
                l++;
            }

            if(m1==m2) return true;
        }
         return false;

    }
};