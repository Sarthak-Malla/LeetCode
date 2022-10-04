#include<iostream>
#include<vector>
using namespace std;

int climbStairs(int n) {
    vector<int> steps(n + 1, 1);

    for (int i = 2; i < n + 1; i++) {
        steps[i] = steps[i-1] + steps[i-2];
    }

    return steps[n];
}

int main(){
    cout << climbStairs(3) << endl;

    return 0;
}