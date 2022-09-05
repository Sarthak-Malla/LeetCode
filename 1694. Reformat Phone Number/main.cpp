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

string reformatNumber(string number){
    int remainder = number.length() % 3;
    string answer = "";
    if (remainder == 0) {
        for (int i = 0; i < number.length() - 3; i += 3){
            answer += number.substr(i, 3) + '-';
        }

        answer += number.substr(number.length() - 3, 3);
    } else if (remainder == 1) {
        for (int i = 0; i < number.length() - 4; i += 3) {
            answer += number.substr(i, 3) + '-';
        }
        answer += number.substr(number.length() - 4, 2) + '-' + number.substr(number.length() - 2, 2);
    } else if (remainder == 2) {
        for (int i = 0; i < number.length() - 2; i += 3) {
            answer += number.substr(i, 3) + '-';
        }
        answer += number.substr(number.length() - 2, 2);
    }

    return answer;
}

int main(){
    string phone_number = "1-23-45 6";
    string p_number = giveNumbers(phone_number);

    string formatted_number = reformatNumber(p_number);

    cout<<formatted_number<<endl;

    return 0;
}