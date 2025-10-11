class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
      unordered_set<string>st(bank.begin(),bank.end());
      if(st.find(endGene)==st.end()) return -1;
      queue<string>q;
      q.push(startGene);
      vector<char>gene;
      gene.push_back('A');
      gene.push_back('G');
      gene.push_back('C');
      gene.push_back('T');
      unordered_set<string>vis;
      vis.insert(startGene);
      int ans=0;
      while(!q.empty()){
       int n=q.size();
       while(n--){
        auto s=q.front();
        q.pop();
        if(s==endGene) return ans;
         for(auto ch:gene){
            for(int i=0;i<8;i++){
                string temp=s;
                if(temp[i]==ch) continue;
                temp[i]=ch;
                if(vis.find(temp)==vis.end()&&st.find(temp)!=st.end()){
                    q.push(temp);
                    vis.insert(temp);
                }
                else continue;

            }
         }
        }
         ans++;
       }
       return -1; 

    }
};