#include<iostream>
#include<string>
using namespace std;

string giveNumbers(string phone_number){
    int digit;
    string number;
    for (int i = 0; i <= phone_number.length(); i++) {
        digit = phone_number[i] - '0';
        if (digit < 10 && digit >= 0) {
            number += phone_number[i];
        }
    }

    return number;
}

string getFormattedNumber(string number){

}

int main(){
    string phone_number = "1-23-45 6";
    string p_number = giveNumbers(phone_number);

    // string formatted_number = getFormattedNumber(p_number);

    // cout<<formatted_number<<endl;
    cout<<p_number<<endl;

    return 0;
}