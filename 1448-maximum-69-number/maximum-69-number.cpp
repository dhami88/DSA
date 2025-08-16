class Solution {
public:
    int maximum69Number (int num) {
        vector<int>zoo;
        while(num>0){
            int dig=num%10;
            zoo.push_back(dig);
            num=num/10;
        }
        reverse(zoo.begin(),zoo.end());
        int n=zoo.size();
       for(int i=0;i<n;i++){
        if(zoo[i]==6){
            zoo[i]=9;
            break;
        }
        else continue;
       }
      int ans=0;
      for(int j=0;j<n;j++){
        ans=ans*10+zoo[j];
              }
              return ans;
    }
};