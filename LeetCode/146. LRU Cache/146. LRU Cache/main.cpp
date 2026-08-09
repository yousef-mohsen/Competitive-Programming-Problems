//
//  main.cpp
//  146. LRU Cache
//
//  Created by Yousef on 08.08.26.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class LRUCache {
  public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (this->m.find(key) != m.end())
        {
            this->last_used = key;
            return m[key];
        }
        else
            return -1;
    }

    void put(int key, int value) {

        //        if(this->m.find(key) !=m.end())
        //        {
        //            m[key] = value;
        //            this->last_used = key;
        //        }
        if (m.size() >= capacity) {
            m.erase(last_used);
        }

        m[key] = value;
        this->last_used = key;
    }

  private:
    unordered_map<int, int> m;
    int capacity;
    int last_used = -1;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

using namespace std;

int main(int argc, const char *argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
