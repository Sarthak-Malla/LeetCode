#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() == 1)
        return 0;
    
    int left = 0, right = 0;
    int count = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (left != right) {
            if (prices[left] > prices[right]) {
                left = right;
            }
        }
        if (prices[right] - prices[left] > count) {
            count = prices[right] - prices[left];
        }
        right++;
    }
    
    return count;
}

int main(){

    vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);

    cout<<maxProfit(prices)<<endl;

    return 0;
}