#include<iostream>
#include<vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();

    // creating a difference array
    vector<int> hash(len, 0);
    for (int i = 0; i < len; i++)
        hash[i] = gas[i] - cost[i];

    // finding the minimum sum value in the difference array
    int m = 0, mini = INT_MAX;
    int sum = 0, idx = 0;
    
    for (int i = 0; i < len; i++) {
        if (hash[i] <= 0)
            if (mini > m + hash[i])
                idx = i;                
        
        sum += hash[i]; 
        m += hash[i];
        mini = min(mini, m);
    }

    if (sum < 0)
        return -1;

    return (idx+1) % len;
}

int main(){
    vector<int> gas = { 1, 2, 3, 4, 5 };
    vector<int> cost = { 3, 4, 5, 1, 2 };
    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}