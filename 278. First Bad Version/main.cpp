#include<iostream>
using namespace std;

bool isBadVersion(int version) {
    return (version >= 99);
}

int firstBadVersion(int n) {
    int left = 1, right = n;
    int mid;

    if (left == right && isBadVersion(left))
        return left;

    while (right - left > 1) {
        mid = (right-left)/2 + left; // 4 2 3
        if (isBadVersion(mid))
            right = mid; // 4
        else if (!isBadVersion(mid)) // 1 2 3 4 5 6 7 8
            left = mid; // 2 3 
    }

    if (isBadVersion(left))
        return left;
    if (isBadVersion(right))
        return right;
    return mid;
}

int main(){
    cout<<firstBadVersion(2126753390)<<endl;

    return 0;
}