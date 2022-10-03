#include<iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n > 1) {
        if (n % 2 != 0)
            ans++;
        
        n /= 2;
    }
    if (n == 1)
        ans++;

    return ans;
}

int main(){
    uint32_t n;
    cin >> n;
    cout << hammingWeight(n) << endl;

    return 0;
}