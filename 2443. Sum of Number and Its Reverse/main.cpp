#include<iostream>
using namespace std;

int reverseDigits(int n) {
    int ans = 0;
    while (n >= 1) {
        ans = 10 * ans + (n%10);
        n = n/10;
    }
    
    return ans;
}

bool sumOfNumberAndReverse(int num) {
    
    for (int i = 0; i <= num; i++) {
        if (i + reverseDigits(i) == num)
            return true;
    }
    
    return false;
}

int main(){
    cout<<sumOfNumberAndReverse(123)<<endl;

    return 0;
}
