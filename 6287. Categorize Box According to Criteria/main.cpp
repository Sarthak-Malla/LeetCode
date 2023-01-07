#include<iostream>
#include<string>
using namespace std;

string categorizeBox(int length, int width, int height, int mass) {
    bool heavy = false, bulky = false;
    string res = "";
    
    if (length >= 10000 || width >= 10000 || height >= 10000 || length >= (1000000000 / width) / height)
        bulky = true;
    
    if (mass >= 100)
        heavy = true;
    
    if (bulky && heavy)
        res = "Both";
    else if (!bulky && !heavy)
        res = "Neither";
    else if (bulky && !heavy)
        res = "Bulky";
    else if (!bulky && heavy)
        res = "Heavy";
    
    return res;
}

int main(){
    int length, width, height, mass;
    cin >> length >> width >> height >> mass;
    cout << categorizeBox(length, width, height, mass);

    return 0;
}