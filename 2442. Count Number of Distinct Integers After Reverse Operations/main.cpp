#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int reverseDigits(int n) {
    int ans = 0;
    while (n >= 1) {
        ans = 10 * ans + (n%10);
        n = n/10;
    }
    
    return ans;
}

int countDistinctIntegers(vector<int>& nums) {
    unordered_map<int, int> hash;
    
    for (int i = 0; i < nums.size(); i++) {
        if (hash.find(nums[i]) == hash.end())
            hash[nums[i]] = 1;
        else 
            hash[nums[i]]++;
        
        int a = reverseDigits(nums[i]);
        if (hash.find(a) == hash.end())
            hash[a] = 1;
        else
            hash[a]++;
    }
    
    
    return hash.size();
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << countDistinctIntegers(nums) << endl;

    return 0;
}