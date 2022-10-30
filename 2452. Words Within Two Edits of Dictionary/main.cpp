#include<iostream>
#include<vector>
using namespace std;

vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> ans = {};
    int count = 0;
    
    for (int i = 0; i < queries.size(); i++) {
        for (int j = 0; j < dictionary.size(); j++) {
            count = 0;
            bool flag = true;
            for (int k = 0; k < queries[i].size(); k++) {
                if (queries[i][k] != dictionary[j][k])
                    count++;
                
                if (count > 2)
                    flag = false;
            }
            
            if (flag) {
                ans.push_back(queries[i]);
                break;
            }
        }
    }
    
    return ans;
}

int main(){
    vector<string> queries = {"word","note","ants","wood"};
    vector<string> dictionary = {"wood","joke","moat"};

    vector<string> ans = twoEditWords(queries, dictionary);

    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<' ';
    }
    cout<<endl;

    return 0;
}