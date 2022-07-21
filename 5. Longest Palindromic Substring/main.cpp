#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPalindrome(string s){
    string reversed = "";

    for (int i = 0; i < s.length(); i++){
        reversed = s[i] + reversed;
    }

    return (s == reversed);
}

string longestPalindrome(string s){
    int len = s.length();
    vector<vector<int> > mat;
    vector<int> inside;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            inside.push_back(-1);
        }

        mat.push_back(inside);
        inside.clear();
    }

    if (len == 1)
        return s;
    
    string current = "";
    string mid = "";
    string longest = "";

    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            current = s.substr(i, j - i + 1);
            if (mat[i][j] < 0){
                if (j - i >= 2){
                    if (mat[i+1][j-1] < 0){
                        mat[i+1][j-1] = isPalindrome(current.substr(1, current.length() - 2));
                    }

                    if (mat[i+1][j-1] && s[i] == s[j]){
                        mat[i][j] = 1;
                    } else {
                        mat[i][j] = 0;
                    }

                } else {
                    mat[i][j] = (s[i] == s[j]);
                }
            }
            if (mat[i][j] == 0)
                continue;

            if (mat[i][j] == 1){
                if (current.length() > longest.length())
                    longest = current;
            }
        }
    }

    return longest;
}

int main(){

    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";

    string ans = longestPalindrome(s);   

    cout<<ans<<endl; 

    return 0;
}