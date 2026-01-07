#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
    int capacity;
    list<int> cache;
    unordered_map<int, list<int>::iterator> pos;

public:
    LRUCache(int cap) : capacity(cap) {}

    void put(int key) {
        if (pos.find(key) != pos.end()) {
            cache.erase(pos[key]);
        } else if (cache.size() == capacity) {
            int last = cache.back();
            cache.pop_back();
            pos.erase(last);
        }
        cache.push_front(key);
        pos[key] = cache.begin();
    }

    void display() {
        for (int x : cache)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    LRUCache lru(3);

    lru.put(1);
    lru.put(2);
    lru.put(3);
    lru.display();

    lru.put(4);
    lru.display();

    return 0;
}
