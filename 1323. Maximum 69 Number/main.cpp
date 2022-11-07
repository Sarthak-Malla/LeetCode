#include<iostream>
#include<string>
using namespace std;

int maximum69Number (int num) {
    string n = to_string(num);

    for (int i = 0; i < n.size(); i++) {
        if (n[i] != '9') {
            n[i] = '9';
            break;
        }
    }

    return stoi(n);
}

int main(){
    cout<<maximum69Number(9669)<<endl;

    return 0;
}
