#include<iostream>
#include<string>

using namespace std;

// checking if all the letters are small
bool allSmall(string word, int index) {
    for (int i = index; i < word.size(); i++) {
        if (word[i] < 97 || word[i] > 122)
            return false;
    }

    return true;
}

// checking if all the letters are big
bool allBig(string word, int index) {
    for (int i = index; i < word.size(); i++) {
        if (word[i] < 65 || word[i] > 90)
            return false;
    }

    return true;
}

bool detectCapitalUse(string word) {
    // if the first letter is small all the letters must be small
    if (word[0] >= 97 && word[0] <= 122)
        return allSmall(word, 1);
    
    // if second letter exists and is small then all the letters must be small
    if (word.size() > 1) 
        if (word[1] >= 97 && word[1] <= 122)
            return allSmall(word, 2);

    // else all the letters must be big
    return allBig(word, 2);
}

int main(){
    string word = "USA";
    cout << detectCapitalUse(word) << endl;

    return 0;
}