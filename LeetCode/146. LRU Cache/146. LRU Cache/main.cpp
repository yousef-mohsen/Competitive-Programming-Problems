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

struct Node {
    int key;
    int value;
    Node * next;
    Node* prev;
    
    Node(int key, int value):
    key(key), value(value), prev(nullptr), next(nullptr){}
};

class LRUCache {
  public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node(0,0);
        this->tail = new Node(0,0);
        
        this->tail->next = this->head;
        this->head->prev = this->tail;
    }

    int get(int key) {
        if (this->m.find(key) != m.end())
        {
            remove_node(m[key]);
            add_node(m[key]);
            return m[key]->value;
        }
        else
            return -1;
    }

    void put(int key, int value) {
        
        if(m.find(key) != m.end())
        {
            m[key]->value = value;
            remove_node(m[key]);
            add_node(m[key]);
            return;
        }
        if (m.size() >= capacity) {
            Node * tmp = this->tail->next;
            m.erase(tmp->key);
            remove_node(tmp);
            delete tmp;
        }
        Node * node = new Node(key, value);
        add_node(node);
        m[key] = node;
        
    }
    

  private:
    unordered_map<int, Node *> m;
    int capacity;
    Node * head;
    Node * tail;
    
    
    void add_node(Node *node)
    {
        node->prev = this->head->prev;
        node->next = this->head;
        
        this->head->prev->next = node;
        this->head->prev = node;
        
    }
    
    void remove_node(Node * node)
    {
        node->prev->next= node->next;
        node->next-> prev = node-> prev;
    }
};



using namespace std;

int main(int argc, const char *argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
