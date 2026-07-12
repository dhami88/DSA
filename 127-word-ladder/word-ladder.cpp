class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>st;
        st.insert(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int len = q.front().second;
            if(word == endWord) return len;
            q.pop();
            for(int j=0;j<word.size();j++){
                char original =word[j];
            for(char i ='a';i<='z';i++){
                word[j]=i;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,len+1});
                }
            }
            word[j] =original;
            }
        }
        return 0;
    }
};