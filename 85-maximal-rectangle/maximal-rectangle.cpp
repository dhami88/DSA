class Solution {
    int largestarea(vector<int>&height){
        int n=height.size();
        stack<int>st;
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]>height[i]){
                int el = height[st.top()];
                st.pop();
                int nse=i;
                int pse=(st.empty())?-1:st.top();
              maxi=max(maxi,el*(nse-pse-1));

            }
            st.push(i);
        }
        while(!st.empty()){
            int el=height[st.top()];
            st.pop();
            int nse=n;
            int pse=(st.empty())?-1:st.top();
            maxi=max(maxi,el*(nse-pse-1));
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else height[j]=0;
            }
            ans=max(ans,largestarea(height));
        }
        return ans;
    }
};