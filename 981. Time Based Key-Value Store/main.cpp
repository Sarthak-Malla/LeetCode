#include<iostream>
#include<map>
using namespace std;

class TimeMap {
public:
    map<string, map<int, string> > record;
    map<string, map<int, string> >::const_iterator itr;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        record[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (record.find(key) != record.end()) {
            for (auto itr = record[key].rbegin(); itr != record[key].rend(); itr++) {
                if (itr->first <= timestamp)
                    return itr->second;
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
