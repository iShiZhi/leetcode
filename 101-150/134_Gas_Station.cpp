class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int curGas = 0;
        int pos = -1;
        
        for (int i = 0; i < gas.size(); i++) {
            curGas += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];
            if (curGas < 0) {
                curGas = 0;
                pos = i;
            }
        }
        
        if (totalGas >= 0) {
            return pos + 1;
        } else {
            return -1;
        }
    }
};