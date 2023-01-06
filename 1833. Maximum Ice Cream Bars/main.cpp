#include<iostream>
#include<vector>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    // getting all the minimum cost at the start
    sort(costs.begin(), costs.end());
    int len = costs.size();

    int n = 0;
    for (int i = 0; i < len; i++) {

        // this condition checks if we can afford the ice cream with the coins we have
        if (coins < costs[i])
            return n;
        
        // we subtract the cost of the ice cream from the coins we have
        coins -= costs[i];

        // increasing the number of ice creams we can buy
        n++;
    }

    return n;
}

int main(){
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;
    cout << maxIceCream(costs, coins) << endl;

    return 0;
}