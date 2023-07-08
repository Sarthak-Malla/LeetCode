#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    vector<int> m;
    stack<int> s;
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);

        int n = m.size();
        if (n == 0) {
            m.push_back(val);
            return;
        }

        for (auto i = m.begin(); i != m.end(); i++) {
            if (*i >= val) {
                m.insert(i, val);
                break;
            }
        }
    }
    
    void pop() {
        int last = s.top();
        s.pop();

        if (last == m[0])
            m.erase(m.begin());
        else {
            for (auto i = m.begin(); i != m.end(); i++) {
                if (*i == last) {
                    m.erase(i);
                    break;
                }
            }
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m[0];
    }
};

int main(){
	MinStack* obj = new MinStack();
	obj->push(1);
	obj->push(2);
	obj->push(3);
	cout << obj->getMin() << endl;
	obj->pop();
	cout << obj->getMin() << endl;
	obj->pop();
	cout << obj->getMin() << endl;

	return 0;
}