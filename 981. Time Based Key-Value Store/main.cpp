#include<iostream>
#include<unordered_map>
using namespace std;

class TimeMap {
public:
    unordered_map<string, unordered_map<int, string> > record;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        record[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (record.find(key) != record.end()) {
            while (timestamp >= 0) {
                if (record[key].find(timestamp) != record[key].end())
                    return record[key][timestamp];

                timestamp--;
            }
        }

        return "";
    }
};

int main(){
    TimeMap* obj = new TimeMap();
    obj->set("foo", "bar", 1);
    cout << obj->get("foo", 1) << endl;
    cout << obj->get("foo", 3) << endl;
    obj->set("foo", "bar2", 4);
    cout << obj->get("foo", 4) << endl;
    cout << obj->get("foo", 5) << endl;

    return 0;
}
