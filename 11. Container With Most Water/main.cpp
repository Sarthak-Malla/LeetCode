#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int area = INT_MIN;
    int curr_area = 0;
    while (left < right) {
        curr_area = min(height[left], height[right]) * (right - left);
        area = max(area, curr_area);

        if (height[left] < height[right])
            left++;
        else if (height[left] >= height[right])
            right--;
    }

    return area;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height);

    return 0;
}