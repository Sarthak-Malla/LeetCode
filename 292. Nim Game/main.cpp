#include<iostream>
using namespace std;

bool canWinNim(int n) {
    return (n%4);
}

int main(){
    int n;
    cin>>n;
    cout<<boolalpha<<canWinNim(n);

    return 0;
}