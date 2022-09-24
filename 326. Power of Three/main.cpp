#include<iostream>
using namespace std;

bool isPowerOfThree(int n) {
    if (n == 1)
        return true;
    if (n < 1) 
        return false;
    if (n % 3 != 0)
        return false;
    
    return isPowerOfThree(n/3);
}

int main(){
    cout<<boolalpha<<isPowerOfThree(45)<<endl;

    return 0;
}