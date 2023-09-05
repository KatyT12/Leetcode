#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mem = {};
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }
        else if (mem.find(head) != mem.end()) {
            return mem[head];
        }
        Node* rnd = NULL; Node* nxt = NULL;
        Node* cpy = new Node(head->val);
        mem[head] = cpy;
        if (head->next) {
            nxt = copyRandomList(head->next);
        }
        if (head->random) {
            rnd = copyRandomList(head->random);
        }
        cpy->next = nxt; cpy->random = rnd;
        return cpy;
    }
};