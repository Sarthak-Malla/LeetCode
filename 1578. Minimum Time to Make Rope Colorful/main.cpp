#include<iostream>
#include<vector>
using namespace std;

string shift(string colors, vector<int>& neededTime, int index) {
    for (int i = index; i < neededTime.size() - 1; i++) {
        colors[i] = colors[i+1];
        neededTime[i] = neededTime[i+1];
    }
    neededTime.pop_back();

    return colors.substr(0, colors.size() - 1);
}
int minCost(string colors, vector<int>& neededTime) {
    int time = 0;
    for (int i = 0; i < colors.size() - 1; i++) {
        if (colors[i+1] == colors[i]) {
            if (neededTime[i+1] < neededTime[i]) {
                time += neededTime[i+1];
                colors = shift(colors, neededTime, i+1);
            }
            else {
                time += neededTime[i];
                colors = shift(colors, neededTime, i);
            }

            i--;
        }
    }

    return time;
}

int main(){
    string colors = "rrrggg";
    vector<int> neededTime = {1, 2, 1, 2, 1, 2};
    cout << minCost(colors, neededTime) << endl;

    return 0;
}
