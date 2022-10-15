#include<iostream>
#include<string>
using namespace std;

int countTime(string time) {
    int count = 1;
    if (time[0] == '?' && time[1] != '?') 
        if (time[1] >= '4')
            count *= 2;
        else
            count *= 3;
    
    if (time[0] == '?' && time[1] == '?')
        count *= 24;
    if (time[0] != '?' && time[1] == '?')
        if (time[0] <= '1')
            count *= 10;
        else
            count *= 4;
    
    if (time[3] == '?' && time[4] != '?')
        count *= 6;
    if (time[4] == '?' && time[3] != '?')
        count *= 10;
    if (time[3] == '?' && time[4] == '?')
        count *= 60;
    
    return count;
}

int main(){
    string time = "2?:?0";
    cout << countTime(time)<<endl;

    return 0;
}