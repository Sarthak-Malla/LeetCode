#include<iostream>
using namespace std;

int getSum(int a, int b) {
    int ans = 0;
    int carry = 0;
    int bit;

    for (int i = 0; i < 32; i++) {
        int last_a = a & 1;
        int last_b = b & 1;

        bit = last_a ^ last_b ^ carry;

        if ((last_a && last_b) || (last_a && carry) || (last_b && carry)) 
            carry = 1;
        else
            carry = 0;

        bit = bit << i;
        ans |= bit;

        a = a >> 1;
        b = b >> 1;
    }

    return ans;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << getSum(a, b) << endl;

    return 0;
}
