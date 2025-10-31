class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalgas=0;
        int totalcost=0;
        for(int i=0;i<n;i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        if(totalgas<totalcost) return -1;
        int curgas=0;
        int idx=0;
        for(int i=0;i<n;i++){
            curgas=curgas+gas[i]-cost[i];
            if(curgas<0){
                idx=i+1;
                curgas=0;
            }
        }
        return idx;
    }
};