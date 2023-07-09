#include <bits/stdc++.h>

using namespace std;

class Car {
public:
    Car(int pos, int speed) {
        this->pos = pos;
        this->speed = speed;
    }
    int pos;
    int speed;
};

int carFleet(int target, vector<int>& position, vector<int>& speed) {
	vector<Car> cars;
	int n = position.size();
	for (int i = 0; i < n; i++)
		cars.emplace_back(position[i], speed[i]);

	sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {return a.pos < b.pos;});

	stack<float> mono;
	for (int i = 0; i < n; i++) {
		float time = (target - cars[i].pos)/(float)(cars[i].speed);
		while (!mono.empty() && time >= mono.top())
			mono.pop();
		
		mono.push(time);
	}

	return mono.size();
}

int main(){
	vector<int> position = {10,8,0,5,3};
	vector<int> speed = {2,4,1,1,3};
	int target = 12;
	cout << carFleet(target, position, speed) << endl;

	return 0;
}