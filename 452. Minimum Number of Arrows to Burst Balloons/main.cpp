#include<iostream>
#include<vector>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    // sort the points based on the starting point, if the starting point is same, sort based on the ending point
    sort(points.begin(), points.end());

    // at least one arrow is used
    int arrows = 1;
    int len = points.size();

    // the current ending point
    int curr = points[0][1];

    for (int i = 1; i < len; i++) {

        // looks at the current ending point is less than the next starting point, so we need to use another arrow
        if (points[i][0] > curr) {
            arrows++;
            curr = points[i][1];
            continue;
        }
        
        // looks at the current ending point is less than the next ending point, so we need to use another arrow
        else if (i + 1 < len && points[i][1] < points[i+1][0]) {
            arrows++;
            curr = points[i+1][1];
            continue;
        }

        // update the current ending point if the next ending point is less than the current ending point
        if (points[i][1] < curr)
            curr = points[i][1];
    }

    return arrows;
}

int main(){
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    cout<<findMinArrowShots(points)<<endl;

    return 0;
}