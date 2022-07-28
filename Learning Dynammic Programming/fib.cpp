#include<iostream>
#include<map>
using namespace std;

int fib(int n, map<int, int> memo){
    if (memo.find(n) != memo.end())
        return memo[n];
    if (n <= 2) return 1;
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

int main(){
    map<int, int> memo;
    cout<<fib(30, memo)<<endl;

    return 0;
}