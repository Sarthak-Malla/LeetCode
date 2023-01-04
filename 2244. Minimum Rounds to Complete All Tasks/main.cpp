#include<iostream>
#include<vector>
using namespace std;

int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> hash;

    // count the number of each task
    for (int i = 0; i < tasks.size(); i++) {
        hash[tasks[i]]++;
    }

    int ans = 0;
    for (auto task : hash) {
        // filter out the task that has not been done at least twice
        if (task.second < 2)
            return -1;
        
        int m = task.second % 3;
        int n = task.second / 3;

        // if divisible by 3, then minimum becomes the number of tasks divided by 3
        if (m == 0)
            ans += n;

        // if not divisible by 3, then minimum becomes the number of tasks divided by 3 + 1
        else
            ans += n + 1;
    }

    return ans;
}

int main(){
    vector<int> tasks = {1, 2, 3, 3, 4, 4, 4, 5, 5, 5};
    cout << minimumRounds(tasks) << endl;

    return 0;
}