#include<iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    vector<string> pos = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    for (int i = 4; i <= score.size(); i++) {
        pos.push_back(to_string(i));
    }
    
    priority_queue<int> q(score.begin(), score.end());
    vector<string> ans(score.size(), "0");
    
    for (int i = 0; i < score.size(); i++) {
        auto itr = find(score.begin(), score.end(), q.top());
        q.pop();
        int index = itr - score.begin();
        
        ans[index] = pos[i];            
    }
    
    return ans;
}

int main(){

    vector<int> score = {5, 4, 3, 2, 1};
    vector<string> ans = findRelativeRanks(score);

    for (int i = 0; i < score.size(); i++) {
        cout<<ans[i]<<endl;
    }

    return 0;
}
