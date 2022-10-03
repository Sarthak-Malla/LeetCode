#include<iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint ans = 0;
    uint bit;
    int counter = 0;
    while (counter < 32) {
        bit = n & 1;
        n = n >> 1;
        ans = ans << 1;
        ans |= bit;

        counter++;
    }

    return ans;
}

int main(){
    uint32_t n = 43261596;
    cout << reverseBits(n) << endl;

    return 0;
}
