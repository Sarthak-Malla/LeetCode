#include<iostream>
#include<string>
using namespace std;

bool isMatch(string s, string p){
    int p_index = 0;
    char repeating_char = ' ';

    for (int i = 0; i < max(s.length(), p.length()); i++){

        if (p_index == p.length() && i >= s.length())
            break;

        if (p[p_index] == '.'){
            p_index++;
            continue;
        }

        if (p[p_index] == '*' && p_index > 0){
            repeating_char = p[p_index - 1];

            if (s[i] == repeating_char)
                continue;
            else if (repeating_char == '.'){
                p_index++;
                continue;
            }
            
            p_index++;
        }
        
        if (s[i] != p[p_index]){

            if (p[p_index] == '.'){
                p_index++;
                continue;
            }

            if (p_index + 1 < p.length() && p[p_index + 1] == '*'){
                p_index += 2;
                continue;
            }

            return false;
        }
        else
            p_index++;
    }

    return true;
}

int main(){
    string s = "aab";
    string p = "c*a*b";

    cout<<boolalpha<<isMatch(s, p)<<endl;


    return 0;
}