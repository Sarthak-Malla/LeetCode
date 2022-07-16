#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    vector<int> mergedArray;

    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size()){
        if (nums1[i] < nums2[j]){
            mergedArray.push_back(nums1[i++]);
        } else {
            mergedArray.push_back(nums2[j++]);
        }
    }

    while (i < nums1.size()){
        mergedArray.push_back(nums1[i++]);
    }

    while (j < nums2.size()){
        mergedArray.push_back(nums2[j++]);
    }

    double ans = 0;
    int s = mergedArray.size();
    if (s % 2 != 0){
        ans = mergedArray[s/2];
    } else {
        ans = (mergedArray[s/2] + mergedArray[s/2 - 1])/2.00000;
    }

    return ans;
}

int main(){

    vector<int> num1, num2;

    num1.push_back(1);
    num1.push_back(2);

    num2.push_back(3);
    num2.push_back(4);

    double ans = findMedianSortedArrays(num1, num2);
    cout<<setprecision(5)<<ans<<endl;

    return 0;
}