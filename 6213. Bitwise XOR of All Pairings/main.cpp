#include<iostream>
#include<vector>
using namespace std;

int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int ans;
    int a = nums1.size();
    int b = nums2.size();
    
    if (a % 2 == 0 && b % 2 == 0)
        return 0;
    else if (a % 2 == 0 && b % 2 != 0) {
        ans = nums1[0];
        for (int i = 1; i < a; i++) {
            ans ^= nums1[i];
        }
    }
    else if (a % 2 != 0 && b % 2 == 0) {
        ans = nums2[0];
        for (int i = 1; i < b; i++) {
            ans ^= nums2[i];
        }
    }
    else {
        ans = nums1[0];
        for (int i = 1; i < a; i++) {
            ans ^= nums1[i];
        }
        for (int i = 0; i < b; i++) {
            ans ^= nums2[i];
        }
    }
    
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }
    cout << xorAllNums(nums1, nums2) << endl;

    return 0;
}