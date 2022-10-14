#include<iostream>
#include<vector>
using namespace std;

int hardestWorker(int n, vector<vector<int>>& logs) {
    int start_time = 0;
    int max_time = INT_MIN;
    int person = n - 1;
    for (int i = 0; i < logs.size(); i++) {
        int work_time = logs[i][1] - start_time;
        start_time = logs[i][1];
        if (max_time < work_time) {
            max_time = work_time;
            person = logs[i][0];
        } else if (max_time == work_time) {
            person = min(logs[i][0], person);
        }
    }
    
    return person;
}

int main(){
    int n = 3;
    vector<vector<int>> logs = {{0, 5}, {1, 2}, {0, 2}};
    cout << hardestWorker(n, logs) << endl;

    return 0;
}