#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int starting_color = image[sr][sc];
    image[sr][sc] = color;
    
    if (sr + 1 < image.size() && image[sr + 1][sc] != color){
        if (image[sr + 1][sc] == starting_color) {
            floodFill(image, sr + 1, sc, color);
        }
    }
    
    if (sc - 1 >= 0 && image[sr][sc - 1] != color){
        if (image[sr][sc - 1] == starting_color) {
            floodFill(image, sr, sc - 1, color);
        }
    }
    
    if (sc + 1 < image[0].size() && image[sr][sc + 1] != color){
        if (image[sr][sc + 1] == starting_color) {
            floodFill(image, sr, sc + 1, color);
        }
    }
    
    if (sr - 1 >= 0 && image[sr - 1][sc] != color){
        if (image[sr - 1][sc] == starting_color) {
            floodFill(image, sr - 1, sc, color);
        }
    }
    
    return image;
    
}

int main(){

    

    return 0;
}