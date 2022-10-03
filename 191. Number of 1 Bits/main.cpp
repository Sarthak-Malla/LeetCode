#include<iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
        ans += n & 1;
        n = n>>1;
    }

    return ans;
}

int main(){
    uint32_t n;
    cin >> n;
    cout << hammingWeight(n) << endl;

    return 0;
}