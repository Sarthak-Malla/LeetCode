#include<iostream>
#include<vector>
using namespace std;

int minCost(string colors, vector<int>& neededTime) {
    vector<int> time(neededTime.size());
    time[0] = 0;

    for (int i = 1; i < neededTime.size(); i++) {
        if (colors[i] != colors[i-1])
            time[i] = time[i-1];
        else {
            time[i] = time[i-1] + min(neededTime[i-1], neededTime[i]);
            if (neededTime[i] < neededTime[i-1]) 
                swap(neededTime[i], neededTime[i-1]);
        }
    }

    return time[time.size() - 1];
}

int main(){
    string colors = "rrrggg";
    vector<int> neededTime = {1, 2, 1, 2, 1, 2};
    cout << minCost(colors, neededTime) << endl;

    return 0;
}
