#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;


class LRUCache {

    struct LinkedItem {
        int key;
        int value;
        LinkedItem* next;
        LinkedItem* prev;
    };

public:
    unordered_map<int, LinkedItem*>* map;
    LinkedItem* head;
    LinkedItem* last;
    
    int curr_size = 0;
    int capacity;
    LRUCache(int capacity) {
        map = new unordered_map<int, LinkedItem*>(capacity);
        this->capacity = capacity;
        head = NULL;
        last = NULL;
    }

    int get(int key) {
        if (map->find(key) != map->end()) {
            int val = map->at(key)->value;     
            push_old(key);
            return val;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        if(map->find(key) != map->end()){
            map->at(key)->value = value;
            push_old(key);
        }
        else if (curr_size < capacity) { 
            push_new(key, value);
        }
        else {
            rem_old();
            push_new(key, value);
        }
    }

private:
    void push_new(int key, int value) {
        LinkedItem* item = new LinkedItem();
        item->value = value;
        item->key = key;
        item->next = head;
        item->prev = NULL;
        if(head){
            head->prev = item;
        }
        head = item;
        map->emplace(key, item);
        curr_size++;

        if(curr_size == 1){
            last = head;
        }
    }

    void push_old(int key) {
        LinkedItem* l = map->at(key);
        if (curr_size > 1 && l != head) {
            
            LinkedItem* temp = head->next;
            if (l->next) {
                std:cout << l->next->value << "\n";
                l->next->prev = l->prev;
            }
            if (l->prev) {       
                l->prev->next = l->next;
            }
            head->prev = l;
            if(last == l && capacity > 1){
                last = l->prev;
                l->prev->next = NULL;
            }
            l->next = head;
            l->prev = NULL;
            head = l;
        }
    }

    void rem_old() {
        if (last == NULL) {
            return;
        }
        else { 
            if(capacity == 1){
                map->erase(map->find(last->key));
                delete last;
                last = NULL;
                head = NULL;
            }else{
                LinkedItem* l = last->prev;
                l->next = NULL;
                map->erase(last->key);
                delete last;
                last = l;
                
            }
            curr_size--;
        }
    }
};