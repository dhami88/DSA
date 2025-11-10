class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        //(nse-pse-1)*heights[i]
        int ans=0;
       for(int i=0;i<n;i++){
        while(!st.empty()&&heights[st.top()]>heights[i]){
            int el=heights[st.top()];
            st.pop();
            int nse=i;
            int pse=(st.empty())?-1:st.top();
          ans=max(ans,(nse-pse-1)*el);
        }
        st.push(i);
       }
        while(!st.empty()){
            int el=heights[st.top()];
            st.pop();
            int nse=n;
            int pse=(st.empty())?-1:st.top();
            ans=max(ans,(nse-pse-1)*el);
        }
       return ans;
    }
};