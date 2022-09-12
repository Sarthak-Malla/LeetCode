#include<iostream>
#include<vector>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {
    int score = 0;
    int max_score = 0;
    sort(tokens.begin(), tokens.end());
    int left = 0, right = tokens.size() - 1;

    while (left <= right) {
        if (power < tokens[left] && score == 0)
            return score;

        do {
            power -= tokens[left++];
            score++;
            if (left > right)
                return score;
        } while (power >= tokens[left]);

        if (score > max_score)
            max_score = score;

        power += tokens[right--];
        score--;
    }

    return max_score;
}

int main(){
    vector<int> tokens;
    // tokens.push_back(43);
    // tokens.push_back(61);
    // tokens.push_back(92);
    tokens.push_back(100);
    tokens.push_back(200);
    tokens.push_back(300);
    tokens.push_back(400);

    int power = 200;

    cout<<bagOfTokensScore(tokens, power)<<endl;
    // cout<<*min_element(tokens.begin(), tokens.end())<<endl;

    return 0;
}
